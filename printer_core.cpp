#include "printer_core.h"


printer_core::printer_core()
{
    this->printer_state = STATE_UNKNOW;
    this->gcode_lock    = true;
    this->gcode_file_path    = "";
    this->uart_dev      = NULL;
    this->reset_pin     = NULL;
    this->error_number  = 0;
    this->line_number   = 0;
    this->uart_timer    = new QTimer();
    this->temper_timer  = new QTimer();
    connect(this->uart_timer,SIGNAL(timeout()),this,SLOT(read_uart()));
    connect(this,SIGNAL(new_line_received()),this,SLOT(handel_uart()));
}

printer_core::~printer_core()
{
    delete this->uart_dev;
    delete this->reset_pin;
}

int printer_core::init_uart()
{
    this->ack_flag = ACK_WAITING;
    int ret = mraa::SUCCESS;

    try
    {
        this->uart_dev = new mraa::Uart(0);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << ", likely invalid platform config" << std::endl;
        ret = mraa::ERROR_INVALID_PLATFORM;
    }

    try
    {
        this->uart_dev = new mraa::Uart("/dev/ttyMFD1");
    }
    catch (std::exception& e)
    {
        std::cout << "UART init faild"<< std::endl;
        std::terminate();
        ret = mraa::ERROR_INVALID_RESOURCE;
    }

    if (this->uart_dev->setBaudRate(115200) != mraa::SUCCESS)
    {
        std::cout << "Error setting parity on UART" << std::endl;
        ret = mraa::ERROR_INVALID_PARAMETER;
    }

    if (this->uart_dev->setMode(8, mraa::UART_PARITY_NONE, 1) != mraa::SUCCESS)
    {
        std::cout << "Error setting parity on UART" << std::endl;
        ret = mraa::ERROR_INVALID_PARAMETER;
    }

    if (this->uart_dev->setFlowcontrol(false, false) != mraa::SUCCESS)
    {
        std::cout << "Error setting flow control UART" << std::endl;
        ret = mraa::ERROR_INVALID_PARAMETER;
    }

    this->reset_pin = new mraa::Gpio(RESET_PIN_NUM);
    if (this->reset_pin == NULL)
    {
        std::cout << "Error setting reset pin" << std::endl;
        ret = mraa::ERROR_INVALID_RESOURCE;
    }
    if (this->reset_pin->dir(mraa::DIR_OUT) != mraa::SUCCESS)
    {
        std::cout << "Error setting reset pin DIR" << std::endl;
        ret = mraa::ERROR_INVALID_PARAMETER;
    }
    this->reset_pin->write(1);

    this->uart_timer->setInterval(20);
    this->uart_timer->start();
    this->temper_timer->setInterval(5000);
    this->temper_timer->start();
    std::cout << "start UART" << std::endl;

    return ret;
}

int printer_core::reset_uart()
{
    int ret = this->reset_pin->write(0);
    usleep(10000);
    ret = this->reset_pin->write(1);
    return ret;
}

int printer_core::write_uart(QString data)
{
    int ret = this->uart_dev->writeStr(data.toStdString());
    return ret;
}

int printer_core::close_uart()
{
    this->uart_dev->~Uart();
}

bool printer_core::uart_data_available(unsigned int time_out_millis)
{
    return this->uart_dev->dataAvailable(time_out_millis);
}

void printer_core::read_uart()
{
    if (this->uart_data_available(0))
    {
        char * data = (char*) malloc(sizeof(char) * READ_LEN);
        if (data == NULL)
        {
            throw std::bad_alloc();
        }
        int v = this->uart_dev->read(data,READ_LEN);
        for (int i = 0;i < v;i++)
        {
            this->uart_buffer.enqueue(data[i]);
            if (data[i] == '\n'  || data[i] == '\r')
            {
//                new_line ++;
                emit this->new_line_received();
            }
        }
//        if (new_line)
//        {
//        }
        return;
    }
    else
    {
        emit this->new_line_received();
        return;
    }
}

int printer_core::flush_uart()
{
    int ret = this->uart_dev->flush();
    return ret;
}

QString printer_core::read_line()
{
    int pos = 0;
    QString ret = "";

    if (this->uart_buffer.empty())
    {
        return ret;
    }
    else
    {
        pos = this->uart_buffer.indexOf('\n');
        if (pos > -1)
        {
            for (int i = 0;i < pos; i++)
            {
                ret += this->uart_buffer.dequeue();
            }
            this->uart_buffer.dequeue();
            qDebug()<<"read line:"<<ret;
            return ret;
        }
    }
}

int printer_core::analyse_uart(QString mesg)
{
    if (mesg.indexOf(U_ECHO) > -1)
    {
        if (mesg.indexOf("READY") > -1)
        {
            qDebug()<<"state -> READY";
            this->printer_state = STATE_STAND_BY;
            this->ack_flag = ACK_OK;
        }
    }
    else if (mesg.indexOf(U_INFO) > -1)
    {
        qDebug()<<"analyse:"<<mesg;
    }
    else if (mesg.indexOf(U_WARN) > -1)
    {
        qDebug()<<"analyse:"<<mesg;
    }
    else if (mesg.indexOf(U_ERROR) > -1)
    {
        this->printer_state = STATE_ERROR;
    }
    return 0;
}

void printer_core::handel_uart()
{
    static QString line_str = "";
    static QString command = "";

    line_str = this->read_line();
    if (line_str != "")
    {
        if (line_str == U_OK) //"ok" retured
        {
            //should send the next line Gcode
            this->ack_flag = ACK_OK;
        }
        else if (line_str.indexOf(U_RESEND) > -1) //"Resend" retured
        {
            this->ack_flag = ACK_RESEND;
        }
        else
        {
            this->analyse_uart(line_str);
        }
    }

    if (this->ack_flag == ACK_RESEND)
    {
        this->send_command(command);
    }
    else if (this->ack_flag == ACK_OK)
    {
        command = this->get_new_command();
        if (command != "")
        {
            this->line_number++;
            this->send_command(command);
        }
    }
}

int printer_core::load_gcodefile(QString file_path)
{
    int ret = 0;
    int file_line = 0;
    QString str = "";
    this->gcode_file_path = file_path;
    this->gcode_f.setFileName(file_path);
    if ( !this->gcode_f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "open file faild,source busy" ;
        ret = -1;
    }

    this->gcode_stream.setDevice(&this->gcode_f);
    for(file_line = 0;;file_line++)
    {
        str = this->gcode_stream.readLine();
        if (this->gcode_stream.atEnd())
        {
            break;
        }

        if (str.indexOf("M104") > -1 || str.indexOf("M109") > -1)  //get temper of ex
        {

        }

        if (str.indexOf("M140") > -1 || str.indexOf("M190") > -1)  //get temper of bed
        {

        }

        if (str.indexOf('Z') > -1 && str.indexOf('Z') > -1) //counting layers
        {
            this->layer_position.append(file_line);
        }

    }
    this->layer_count = this->layer_position.length();
    this->gcode_stream.seek(0);
    qDebug()<<"layer count:"<<this->layer_count;

    return ret;
}



QString printer_core::get_gcode_line_frome_file()
{
    QString str = "";
    for(;;)
    {
        str = this->gcode_stream.readLine();
        if (str.startsWith('\n') || str.startsWith('\r') || str.startsWith(';'))
        {
            if (str.indexOf('LAYER') > -1)
            {
                this->layer_number = 0;//
            }
            continue;
        }
        else
        {
            str = str.section(';',0,0);
            return str;
        }
    }
}

QString printer_core::get_new_command()
{
    QString ret = "";
    if (!this->send_buffer.empty())
    {
        ret = this->send_buffer.dequeue();
        return ret;
    }

    if ((!this->gcode_lock) && (!this->gcode_stream.atEnd()) && (this->gcode_stream.device() != 0))
    {
        ret = this->get_gcode_line_frome_file();
        return ret;
    }
    return ret;
}

QString printer_core::add_checksum(QString gcode)
{
    QString ret = "";
    QString line = QString::number(this->line_number,10);
    QString tmp = "N" + line + gcode;
    int checksum = 0;

    for(int i = 0;i < tmp.length();i++)
    {
        checksum ^= tmp[i].toAscii();
    }
    ret = QString::number(checksum,10);

    ret = "N"+line+' '+gcode+" *"+ret+'\n';
    return ret;
}

int printer_core::send_command(QString command)
{
    if (command == "")
    {
        return -1;
    }
    QString str = this->add_checksum(command);

    qDebug()<<"send:"<<str;
    this->ack_flag = ACK_WAITING;
    this->write_uart(str);
    return 0;
}

int printer_core::push_commands(QString commands)
{
    QStringList sections = commands.split(",");

    for (int i = 0;i<sections.length();i++)
    {
        this->send_buffer.append(sections[i]);
    }
    qDebug()<<"push:"<<this->send_buffer;
    return 0;
}

void printer_core::change_state(int state)
{
    this->task_state = state;
    emit this->task_state_change(state);
}

int printer_core::begin_task()
{
    qDebug()<<"state :"<<this->printer_state;
    if (this->printer_state == STATE_STAND_BY)
    {

        qDebug()<<"begin task";
        this->gcode_lock = false;
        this->change_state(STATE_PRINTING);
        return TASK_SUCCESS;
    }
    return TASK_MACHINE_BUSY;
}

int printer_core::cancel_task()
{

    if (this->printer_state == STATE_PRINTING || this->printer_state == STATE_PAUSE)
    {
        this->gcode_lock = true;
        this->gcode_stream.setDevice(0);
        this->gcode_f.close();
        this->change_state(STATE_STAND_BY);
        return TASK_SUCCESS;
    }
    return TASK_MACHINE_BUSY;
}

int printer_core::pause_task()
{
    if (this->printer_state == STATE_PRINTING)
    {
        this->gcode_lock = true;
        this->change_state(STATE_PAUSE);
        this->push_commands("M100");
    }

    return 0;
}

int printer_core::resume_task()
{
    return 0;
}

int printer_core::save_task()
{
    return 0;
}

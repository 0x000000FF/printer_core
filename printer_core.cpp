#include "printer_core.h"


printer_core::printer_core()
{
    this->printer_state = READY;
    this->printer_buzy  = true;
    this->gcode_file_path    = "";
    this->gcode_line    = "";
    this->uart_dev      = NULL;
    this->reset_pin     = NULL;
    this->error_number  = 0;
    this->line_number   = 0;
    this->uart_timer    = new QTimer();
    connect(this->uart_timer,SIGNAL(timeout()),this,SLOT(read_uart()));
    connect(this,SIGNAL(new_line_received(int)),this,SLOT(handel_uart(int)));

}

printer_core::~printer_core()
{
    delete this->uart_dev;
    delete this->reset_pin;
}

int printer_core::init_uart()
{
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

this->uart_timer->setInterval(100);
    this->uart_timer->start();
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

int printer_core::write_uart(std::string data)
{
    int ret = this->uart_dev->writeStr(data);
    return ret;
}

bool printer_core::uart_data_available(unsigned int time_out_millis)
{
    return this->uart_dev->dataAvailable(time_out_millis);
}

void printer_core::read_uart()
{
    int new_line = 0;

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
            if (data[i] == '\n'  || data[i] == '\r')
            {
                new_line ++;
            }
            this->uart_buffer.push(data[i]);
            std::cout<<data[i];
        }
        if (new_line)
        {
            emit this->new_line_received(new_line);
        }
        return;
    }
    else
    {
        return;
    }
}

int printer_core::flush_uart()
{
    int ret = this->uart_dev->flush();
    return ret;
}

std::string printer_core::read_line()
{
    char *str = new char[READ_LEN];
    char tmp = '\0';
    std::string ret = "";

    std::cout<<this->str_buffer<<std::endl;

    if (this->uart_buffer.empty())
    {
        return str;
    }
    else
    {
        for (int i = 0;i < this->uart_buffer.size();i++)
        {
            tmp = this->uart_buffer.front();
            this->uart_buffer.pop();
            if (tmp == '\n' || tmp == '\r')
            {
                std::strcpy(str,this->str_buffer.c_str());
                ret = std::string(str);
                this->str_buffer = "";

                return ret;
            }
            this->str_buffer += this->uart_buffer.front();
        }
        return "";
    }
}

void printer_core::handel_uart(int line_count)
{
    std::string line_str = "";
    for(int line = 0;line < line_count;line ++)
    {
        line_str = this->read_line();
        std::cout<<line<<":"<<std::endl;
        std::cout<<line_str<<std::endl;
    }
}

int printer_core::load_gcodefile(std::string file_path)
{
    int ret = 0;
    this->gcode_file_path = file_path;
    this->gcode.open(this->gcode_file_path.c_str());
    if (this->gcode.is_open())
    {
        ret = -1;
        std::cout << "open file faild,source busy" << std::endl;
    }
    return ret;
}

std::string printer_core::add_checksum()
{
    std::string ret = "";
    std::string tmp = "";
    std::stringstream ss;
    int checksum = 0;
    ss << this->line_number;
    ss >> tmp;
    tmp = "N"+tmp+this->gcode_line;

    for(int i = 0;i < tmp.length();i++)
    {
        std::cout<<tmp[i]<<std::endl;
        checksum ^= tmp[i];
    }

    ss << checksum;
    ss >> ret;

    ret = tmp + ret;
    return ret;
}


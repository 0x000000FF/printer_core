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

std::string printer_core::read_uart(int length)
{
    std::string ret = this->uart_dev->readStr(length);
    return ret;
}

int printer_core::flush_uart()
{
    int ret = this->uart_dev->flush();
    return ret;
}

bool printer_core::uart_data_available(unsigned int time_out_millis)
{
    return this->uart_dev->dataAvailable(time_out_millis);
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
    std::stringstream ss;
    int checksum = 0;
    ss << this->line_number;
    ss >> ret;
    ret = "N"+ret+this->gcode_line;

    for(int i = 0;i < ret.length();i++)
    {
        std::cout<<ret[i]<<std::endl;
        checksum ^= ret[i];
    }
//    std::cout<<checksum<<std::endl;
    return ret;
}

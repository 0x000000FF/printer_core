#include "printer_core.h"

printer_core::printer_core()
{
    this->printer_state = READY;
    this->printer_buzy  = true;
    this->gcode_file    = "";
    this->uart_dev      = NULL;
    this->reset_pin     = NULL;
    this->error_number  = 0;
    this->line_number   = 0;
}


printer_core::~printer_core()
{
    delete this->uart_dev;
}

int printer_core::init_uart()
{
    try
    {
        this->uart_dev = new mraa::Uart(0);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << ", likely invalid platform config" << std::endl;
        return -1;
    }

    try
    {
        this->uart_dev = new mraa::Uart("/dev/ttyMFD1");
    }
    catch (std::exception& e)
    {
        std::cout << "UART init faild"<< std::endl;
        std::terminate();
        return -1;
    }

    if (this->uart_dev->setBaudRate(115200) != mraa::SUCCESS)
    {
        std::cout << "Error setting parity on UART" << std::endl;
    }

    if (this->uart_dev->setMode(8, mraa::UART_PARITY_NONE, 1) != mraa::SUCCESS)
    {
        std::cout << "Error setting parity on UART" << std::endl;
    }

    if (this->uart_dev->setFlowcontrol(false, false) != mraa::SUCCESS)
    {
        std::cout << "Error setting flow control UART" << std::endl;
    }

    this->reset_pin = new mraa::Gpio();
    if (this->reset_pin)

    std::cout << "serial init success!" << std::endl;
    return mraa::SUCCESS;
}

int printer_core::reset_uart()()
{

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



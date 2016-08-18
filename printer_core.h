#ifndef PRINTER_CORE_H
#define PRINTER_CORE_H

#include <unistd.h>
#include <iostream>
#include <exception>
#include "mraa.hpp"
#include <QString>

#define ERROR     (-1)
#define READY       0
#define PRINTING    1
#define PAUSED      2
#define LEVELING    3
#define HEATING     4

class printer_core
{
private:
    int printer_state;
    bool printer_buzy;
    QString gcode_file;

    mraa::Uart* uart_dev;
    mraa::Gpio* reset_pin;

    int error_number;
    int line_number;



public:
    printer_core();
    ~printer_core();

    int init_uart();
    int reset_uart();
    std::string read_uart(int lengtn);
    int write_uart(std::string mesg);
    int flush_uart();
    int close_uart();

    int begin_task();
    int cancel_task();
    int pause_task();
    int resume_task();
    int save_task();

    int get_state();
};

#endif // PTINTER_CORE_H

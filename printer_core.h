#ifndef PRINTER_CORE_H
#define PRINTER_CORE_H

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <exception>
#include "mraa.hpp"
#include <QString>
#include <sstream>
#include <queue>
#include <vector>
#include <QTimer>


#define ERROR     (-1)
#define READY       0
#define PRINTING    1
#define PAUSED      2
#define LEVELING    3
#define HEATING     4

#define RESET_PIN_NUM          36      //mraa 36,linux pin 14

#define RECV_BUFFER_LEN        1024
#define READ_LEN               256
#define GCODE_LEN              128
#define UART_READ_TIME_OUT     10      //ms
#define UART_CONNECT_TIME_OUT  10000   //ms

#define U_OK   "ok"
#define U_RESEND  "resend"

const std::string pause_command[] =
{
   "M100"
};

const std::vector<std::string> resume_command =
{
    "G90","M82","M107","G28","G34"
};


enum GCODE_style
{
    UNKNOW = 0,
    SIMPLIFY,
    CURA,
    SLIC3R,
};

class printer_core : public QObject
{
    Q_OBJECT

private:
    int printer_state;
    bool printer_buzy;
    std::string gcode_file_path;
    std::ifstream gcode;

    mraa::Uart* uart_dev;
    mraa::Gpio* reset_pin;

    int error_number;
    int line_number;

    char recve_buffer[RECV_BUFFER_LEN];
    std::string gcode_line;

    int layer_number;
    GCODE_style gcode_style;

    QTimer *uart_timer;
    std::queue<char> uart_buffer;
    std::string str_buffer;

    std::queue<std::string> send_buffer;

    float position[3] = {0.0,0.0,0.0};
    float E_temperature = 0.0;
    float B_temperature = 0.0;
    float E_target_temperature = 0.0;
    float B_target_temperature = 0.0;

private:
    std::string get_gcode_line(int line);
    std::string add_checksum();

public:
    printer_core();
    ~printer_core();

    int init_uart();
    int reset_uart();
    int write_uart(std::string mesg);
    int flush_uart();
    bool uart_data_available(unsigned int time_out_millis);
    int close_uart();
    std::string read_line();

    int load_gcodefile(std::string file_path);
    int begin_task();
    int cancel_task();
    int pause_task();
    int resume_task();
    int save_task();
    int send_command();
    int push_commands(std::string commands[]);

    int get_state();

signals:
    void new_line_received(int line_count);

public slots:
    void read_uart();
    void handel_uart(int line_count);

};

#endif // PTINTER_CORE_H

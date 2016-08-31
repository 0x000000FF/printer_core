#ifndef PRINTER_CORE_H
#define PRINTER_CORE_H

#include <unistd.h>
#include <iostream>
#include <QString>
#include <QQueue>
#include <QStringList>
#include <QTextStream>
#include <QTimer>
#include <QtCore>
#include <QtCore/QObject>

#include "mraa.hpp"
#include "error_num.h"

#include <QDebug>

#define RESET_PIN_NUM          36      //mraa 36,linux pin 14

#define RECV_BUFFER_LEN        1024
#define READ_LEN               256
#define GCODE_LEN              128
#define UART_READ_TIME_OUT     10      //ms
#define UART_CONNECT_TIME_OUT  10000   //ms

#define KEY_WORD_SIMPLIFY      "Simplify3D"
#define KEY_WORD_CURA          ""
#define KEY_WORD_SLIC3R        "Slic3r"

#define U_OK      "ok"
#define U_RESEND  "Resend"
#define U_ECHO    "ECHO>"
#define U_INFO    "INFO>"
#define U_WARN    "WARN>"
#define U_ERROR   "ERROR>"

//const std::string reset_command = "G28\nG29\nG1 X1 Y179.5 Z15 F4800\nG33\nG1 Z10\nG1 F4800 X110 Y90 Z1\nM160\n";

//const std::string cancel_command  = "M104 S0\nG28\n";

//const std::string pause_command = "M100\n";

//const std::string resume_command =
//        "G90\nM82\nM107\nG28\nG34\nG1 F6000 Zz\nG92 E0\nG1 F200 E20\nG91\nG1 X-10 Y-10 F12000\n\
//        G1 X10 Y10\nG1 X-10 Y-10\nG1 X10 Y10\nG1 X-10 Y-10\nG90\nG1 F18000 Xx Yy\nG1 F6000 Zz\nG1 F1680 E20.4\nG92 Ee";

//const std::string leveling_command = "G28\nG29\nG1 X1 Y179.5 Z15 F4800\nG33\nG1 Z10\nG1 F4800 X110 Y90 Z1\nM160\n";

enum GCODE_style
{
    STYLE_UNKNOW = 0,
    STYLE_SIMPLIFY,
    STYLE_CURA,
    STYLE_SLIC3R,
};

enum work_state
{
    STATE_UNKNOW = -2,
    STATE_ERROR,
    STATE_STAND_BY,
    STATE_PRINTING,
    STATE_PAUSE,
    STATE_LEVELING,
};

enum ack_state
{
    ACK_OK = 0,
    ACK_RESEND,
    ACK_WAITING,
};

class printer_core : public QObject
{
    Q_OBJECT

private:
    int printer_state;
    int task_state;
    int is_heating;
    int  ack_flag;
    QString gcode_file_path;
    QFile gcode_f;
    QTextStream gcode_stream;

    mraa::Uart* uart_dev;
    mraa::Gpio* reset_pin;

    int error_number;
    int line_number;
    int line_count;
    int gcode_file_line;

    int layer_number;
    int layer_count;
    GCODE_style gcode_style;

    QTimer *uart_timer;
    QQueue<char> uart_buffer;

    QQueue<QString> send_buffer;

    bool gcode_lock;
    float current_position[3] = {0.0,0.0,0.0};
    int cuttent_F = 0.0;
    float current_E = 0.0;
    float E_temperature[2] = {0.0,0.0};
    float B_temperature[2] = {0.0,0.0};

    QList<int> layer_position;

    QTimer *temper_timer;

    void change_state(int state);

private:
    QString get_gcode_line_frome_file();
    QString get_new_command();
    int analyse_uart(QString mesg);
    QString add_checksum(QString gcode);
    QString generate_gcode(QString);

public:
    printer_core();
    ~printer_core();

    int init_uart();
    int reset_uart();
    int write_uart(QString mesg);
    int flush_uart();
    bool uart_data_available(unsigned int time_out_millis);
    int close_uart();
    QString read_line();

    int send_command(QString command);
    int push_commands(QString commands);

    int get_state();

public Q_SLOTS:
    int load_gcodefile(QString file_path);
    int begin_task();
    int cancel_task();
    int pause_task();
    int resume_task();
    int save_task();

Q_SIGNALS: // SIGNALS
    void machine_state_change(int state);
    void task_state_change(int state);

signals:
    void new_line_received();

public slots:
    void read_uart();
    void handel_uart();

};

#endif // PTINTER_CORE_H

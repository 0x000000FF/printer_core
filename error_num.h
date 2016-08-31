#ifndef ERROR_NUM_H
#define ERROR_NUM_H

enum machine_error
{
    MACHINE_NO_CONECT = 1,

};

enum task_error
{
    TASK_SUCCESS = 0,
    TASK_MACHINE_ERROR,
    TASK_MACHINE_BUSY,
    TASK_NO_SUCH_FILE,
    TASK_CAN_NOT_OPEN,
    TASK_INVALID_FILE,
};

#endif // ERROR_NUM_H

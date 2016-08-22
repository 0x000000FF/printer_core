#include <QCoreApplication>
#include "printer_core.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printer_core *myprinter = new printer_core();

    myprinter->init_uart();
    myprinter->reset_uart();
    std::string tmp;

    std::cout<<"begin read"<<std::endl;
//    for (;;)
//    {
        std::cout<<"read line"<<std::endl;
        tmp = myprinter->read_line();
        std::cout<<tmp<<std::endl;

//    }

    return a.exec();
}

#include <QCoreApplication>
#include "printer_core.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printer_core *myprinter = new printer_core();

    myprinter->init_uart();
    std::string tmp;


    std::cout<<"begin read"<<std::endl;
    for(;;)
    {
        myprinter->write_uart("hello");
        tmp = myprinter->read_uart(6);
        std::cout<<tmp<<std::endl;
        sleep(1);
    }

    return a.exec();
}

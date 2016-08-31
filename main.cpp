#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include "printer_core.h"
#include "core_adaptor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printer_core *myprinter = new printer_core();

    new core_adaptor(myprinter);

    QDBusConnection core_dbus = QDBusConnection::systemBus();
    if (core_dbus.registerObject("/",myprinter))
    {
        qDebug()<<"register object success";
    }

    if (core_dbus.registerService("com.mostfun.pro"))
    {
        qDebug()<<"register service success";
    }

    myprinter->init_uart();
    myprinter->reset_uart();

    std::cout<<"begin read"<<std::endl;

    myprinter->push_commands("G1 X116.598 Y45.265,G1 X117.598 Y46.265,G1 X117.937 Y46.265,G1 X117.937 Y46.604");

    std::cout<<"load"<<std::endl;
    myprinter->load_gcodefile("./Mander.gcode");

    return a.exec();
}

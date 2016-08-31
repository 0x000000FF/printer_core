#include "core_adaptor.h"
#include <QtCore/QMetaObject>

core_adaptor::core_adaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

core_adaptor::~core_adaptor()
{

}

int core_adaptor::load_gcodefile(QString file_path)
{
    int ret;
    QMetaObject::invokeMethod(parent(),"load_gcodefile",Q_ARG(QString,file_path),Q_RETURN_ARG(int,ret));
    return ret;
}

int core_adaptor::begin_task()
{
    int ret;
    QMetaObject::invokeMethod(parent(),"begin_task",Q_RETURN_ARG(int,ret));
    return ret;
}

int core_adaptor::cancel_task()
{
    int ret;
    QMetaObject::invokeMethod(parent(),"cancel_task",Q_RETURN_ARG(int,ret));
    return ret;
}

int core_adaptor::pause_task()
{
    int ret;
    QMetaObject::invokeMethod(parent(),"pause_task",Q_RETURN_ARG(int,ret));
    return ret;
}

int core_adaptor::resume_task()
{
    int ret;
    QMetaObject::invokeMethod(parent(),"resume_task",Q_RETURN_ARG(int,ret));
    return ret;
}

int core_adaptor::save_task()
{
    int ret;
    QMetaObject::invokeMethod(parent(),"save_task",Q_RETURN_ARG(int,ret));
    return ret;
}

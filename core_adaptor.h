#ifndef CORE_ADAPTOR_H
#define CORE_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>

class core_adaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.mostfun.printer.CoreInterface")
    Q_CLASSINFO("D-Bus Introspection", ""
                    "  <interface name=\"com.mostfun.printer.CoreInterface\">\n"
                    "    <method name=\"load_task\">\n"
                    "    <method name=\"begin_task\">\n"
                    "    <method name=\"cancel_task\">\n"
                    "    <method name=\"pause_task\">\n"
                    "    <method name=\"resume_task\">\n"
                    "    <method name=\"save_task\">\n"
                    "    <signal name=\"machine_state_change\"> \n"
                    "      <arg direction=\"out\" type=\"i\" name=\"state\"/>\n"
                    "    </signal>\n"
                    "    <signal name=\"task_state_change\"> \n"
                    "      <arg direction=\"out\" type=\"i\" name=\"state\"/>\n"
                    "    </signal>\n"
                    "  </interface>\n"
                    "")
public:
    core_adaptor(QObject *parent);
    virtual ~core_adaptor();

public:
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

};

#endif // CORE_ADAPTOR_H

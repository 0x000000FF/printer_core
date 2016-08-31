/****************************************************************************
** Meta object code from reading C++ file 'printer_core.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "printer_core.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printer_core.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_printer_core[] = {

 // content:
       6,       // revision
       0,       // classname
       2,   14, // classinfo
      10,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
      38,   13,
     473,   54,

 // signals: signature, parameters, type, tag, flags
     500,  494,  493,  493, 0x05,
     529,  518,  493,  493, 0x05,

 // slots: signature, parameters, type, tag, flags
     566,  556,  552,  493, 0x0a,
     590,  493,  552,  493, 0x0a,
     603,  493,  552,  493, 0x0a,
     617,  493,  552,  493, 0x0a,
     630,  493,  552,  493, 0x0a,
     644,  493,  552,  493, 0x0a,
     656,  493,  493,  493, 0x0a,
     668,  518,  493,  493, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_printer_core[] = {
    "printer_core\0com.mostfun.printer.core\0"
    "D-Bus Interface\0"
    "  <interface name=\"com.mostfun.printer.core\">\n    <method name=\"be"
    "gin_task\">\n    <method name=\"cancel_task\">\n    <method name=\"pau"
    "se_task\">\n    <method name=\"resume_task\">\n    <method name=\"save"
    "_task\">\n    <method name=\"load_task\">\n      <arg name=\"file_path"
    "\" type=\"s\" direction=\"out\"/>\n    </method> \n    <signal name=\""
    "state_change\"> \n       <arg name=\"state\" type=\"i\" direction=\"ou"
    "t\"/>\n    </signal> \n  </interface>\n\0"
    "D-Bus Introspection\0\0state\0state_change(int)\0"
    "line_count\0new_line_received(int)\0int\0"
    "file_path\0load_gcodefile(QString)\0"
    "begin_task()\0cancel_task()\0pause_task()\0"
    "resume_task()\0save_task()\0read_uart()\0"
    "handel_uart(int)\0"
};

void printer_core::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        printer_core *_t = static_cast<printer_core *>(_o);
        switch (_id) {
        case 0: _t->state_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->new_line_received((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->load_gcodefile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->begin_task();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->cancel_task();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->pause_task();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->resume_task();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = _t->save_task();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: _t->read_uart(); break;
        case 9: _t->handel_uart((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData printer_core::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject printer_core::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_printer_core,
      qt_meta_data_printer_core, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &printer_core::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *printer_core::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *printer_core::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_printer_core))
        return static_cast<void*>(const_cast< printer_core*>(this));
    return QObject::qt_metacast(_clname);
}

int printer_core::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void printer_core::state_change(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void printer_core::new_line_received(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

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
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   13,   13,   13, 0x0a,
      60,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_printer_core[] = {
    "printer_core\0\0line_count\0"
    "new_line_received(int)\0read_uart()\0"
    "handel_uart(int)\0"
};

void printer_core::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        printer_core *_t = static_cast<printer_core *>(_o);
        switch (_id) {
        case 0: _t->new_line_received((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->read_uart(); break;
        case 2: _t->handel_uart((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void printer_core::new_line_received(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

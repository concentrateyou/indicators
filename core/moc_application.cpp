/****************************************************************************
** Meta object code from reading C++ file 'application.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "application.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'application.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_core__Application_t {
    QByteArrayData data[21];
    char stringdata[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_core__Application_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_core__Application_t qt_meta_stringdata_core__Application = {
    {
QT_MOC_LITERAL(0, 0, 17), // "core::Application"
QT_MOC_LITERAL(1, 18, 16), // "indicatorChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 12), // "indexChanged"
QT_MOC_LITERAL(4, 49, 12), // "modulChanged"
QT_MOC_LITERAL(5, 62, 4), // "init"
QT_MOC_LITERAL(6, 67, 6), // "create"
QT_MOC_LITERAL(7, 74, 4), // "load"
QT_MOC_LITERAL(8, 79, 4), // "save"
QT_MOC_LITERAL(9, 84, 8), // "addIndex"
QT_MOC_LITERAL(10, 93, 11), // "removeIndex"
QT_MOC_LITERAL(11, 105, 9), // "editIndex"
QT_MOC_LITERAL(12, 115, 9), // "addModule"
QT_MOC_LITERAL(13, 125, 12), // "removeModule"
QT_MOC_LITERAL(14, 138, 10), // "editModule"
QT_MOC_LITERAL(15, 149, 9), // "indicator"
QT_MOC_LITERAL(16, 159, 9), // "Indicator"
QT_MOC_LITERAL(17, 169, 6), // "moduls"
QT_MOC_LITERAL(18, 176, 10), // "modulGroup"
QT_MOC_LITERAL(19, 187, 7), // "indexes"
QT_MOC_LITERAL(20, 195, 10) // "indexGroup"

    },
    "core::Application\0indicatorChanged\0\0"
    "indexChanged\0modulChanged\0init\0create\0"
    "load\0save\0addIndex\0removeIndex\0editIndex\0"
    "addModule\0removeModule\0editModule\0"
    "indicator\0Indicator\0moduls\0modulGroup\0"
    "indexes\0indexGroup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_core__Application[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       3,  140, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   82,    2, 0x0a /* Public */,
       6,    1,   83,    2, 0x0a /* Public */,
       7,    1,   86,    2, 0x0a /* Public */,
       8,    1,   89,    2, 0x0a /* Public */,
       9,    6,   92,    2, 0x0a /* Public */,
      10,    1,  105,    2, 0x0a /* Public */,
      11,    6,  108,    2, 0x0a /* Public */,
      12,    4,  121,    2, 0x0a /* Public */,
      13,    1,  130,    2, 0x0a /* Public */,
      14,    3,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,    2,    2,
    QMetaType::Bool, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Bool, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Double,    2,    2,    2,

 // properties: name, type, flags
      15, 0x80000000 | 16, 0x00495009,
      17, 0x80000000 | 18, 0x00495009,
      19, 0x80000000 | 20, 0x00495009,

 // properties: notify_signal_id
       0,
       2,
       1,

       0        // eod
};

void core::Application::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Application *_t = static_cast<Application *>(_o);
        switch (_id) {
        case 0: _t->indicatorChanged(); break;
        case 1: _t->indexChanged(); break;
        case 2: _t->modulChanged(); break;
        case 3: _t->init(); break;
        case 4: _t->create((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->load((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->save((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->addIndex((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 8: { bool _r = _t->removeIndex((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->editIndex((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 10: _t->addModule((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 11: { bool _r = _t->removeModule((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->editModule((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Application::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Application::indicatorChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Application::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Application::indexChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Application::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Application::modulChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject core::Application::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_core__Application.data,
      qt_meta_data_core__Application,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *core::Application::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *core::Application::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_core__Application.stringdata))
        return static_cast<void*>(const_cast< Application*>(this));
    return QObject::qt_metacast(_clname);
}

int core::Application::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Indicator*>(_v) = getIndicator(); break;
        case 1: *reinterpret_cast< modulGroup*>(_v) = getModuls(); break;
        case 2: *reinterpret_cast< indexGroup*>(_v) = getIndexes(); break;
        default: break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void core::Application::indicatorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void core::Application::indexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void core::Application::modulChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

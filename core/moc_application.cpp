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
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'application.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_core__Application_t {
    QByteArrayData data[18];
    char stringdata[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_core__Application_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_core__Application_t qt_meta_stringdata_core__Application = {
    {
QT_MOC_LITERAL(0, 0, 17), // "core::Application"
QT_MOC_LITERAL(1, 18, 7), // "changed"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "init"
QT_MOC_LITERAL(4, 32, 6), // "create"
QT_MOC_LITERAL(5, 39, 4), // "load"
QT_MOC_LITERAL(6, 44, 4), // "save"
QT_MOC_LITERAL(7, 49, 8), // "addIndex"
QT_MOC_LITERAL(8, 58, 11), // "removeIndex"
QT_MOC_LITERAL(9, 70, 9), // "editIndex"
QT_MOC_LITERAL(10, 80, 9), // "addModule"
QT_MOC_LITERAL(11, 90, 12), // "removeModule"
QT_MOC_LITERAL(12, 103, 10), // "editModule"
QT_MOC_LITERAL(13, 114, 4), // "show"
QT_MOC_LITERAL(14, 119, 9), // "indicator"
QT_MOC_LITERAL(15, 129, 7), // "indexes"
QT_MOC_LITERAL(16, 137, 15), // "QList<QObject*>"
QT_MOC_LITERAL(17, 153, 7) // "modules"

    },
    "core::Application\0changed\0\0init\0create\0"
    "load\0save\0addIndex\0removeIndex\0editIndex\0"
    "addModule\0removeModule\0editModule\0"
    "show\0indicator\0indexes\0QList<QObject*>\0"
    "modules"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_core__Application[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       3,  146, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   80,    2, 0x0a /* Public */,
       4,    1,   81,    2, 0x0a /* Public */,
       5,    1,   84,    2, 0x0a /* Public */,
       6,    1,   87,    2, 0x0a /* Public */,
       7,    6,   90,    2, 0x0a /* Public */,
       8,    1,  103,    2, 0x0a /* Public */,
       9,    6,  106,    2, 0x0a /* Public */,
      10,    4,  119,    2, 0x0a /* Public */,
      10,    3,  128,    2, 0x2a /* Public | MethodCloned */,
      11,    1,  135,    2, 0x0a /* Public */,
      12,    3,  138,    2, 0x0a /* Public */,
      13,    0,  145,    2, 0x0a /* Public */,

 // signals: parameters
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
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double,    2,    2,    2,
    QMetaType::Bool, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Double,    2,    2,    2,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::QObjectStar, 0x00495001,
      15, 0x80000000 | 16, 0x00495009,
      17, 0x80000000 | 16, 0x00495009,

 // properties: notify_signal_id
       0,
       0,
       0,

       0        // eod
};

void core::Application::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Application *_t = static_cast<Application *>(_o);
        switch (_id) {
        case 0: _t->changed(); break;
        case 1: _t->init(); break;
        case 2: _t->create((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->load((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->save((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->addIndex((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 6: { bool _r = _t->removeIndex((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->editIndex((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 8: _t->addModule((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 9: _t->addModule((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 10: { bool _r = _t->removeModule((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->editModule((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 12: _t->show(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Application::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Application::changed)) {
                *result = 0;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
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
        case 0: *reinterpret_cast< QObject**>(_v) = getIndicatorForQML(); break;
        case 1: *reinterpret_cast< QList<QObject*>*>(_v) = getIndexesForQML(); break;
        case 2: *reinterpret_cast< QList<QObject*>*>(_v) = getModulsForQML(); break;
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void core::Application::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

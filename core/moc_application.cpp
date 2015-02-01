/****************************************************************************
** Meta object code from reading C++ file 'application.hpp'
**
** Created: Sat Jan 31 16:23:18 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "application.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'application.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_core__Application[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       3,   79, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      38,   18,   18,   18, 0x05,
      53,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   18,   18,   18, 0x0a,
      75,   18,   18,   18, 0x0a,
      91,   18,   18,   18, 0x0a,
     105,   18,   18,   18, 0x0a,
     125,  119,   18,   18, 0x0a,
     180,   18,  175,   18, 0x0a,
     197,  119,   18,   18, 0x0a,
     252,  248,   18,   18, 0x0a,
     289,   18,  175,   18, 0x0a,
     310,  307,   18,   18, 0x0a,

 // properties: name, type, flags
     351,  341, 0x00495009,
     372,  361, 0x00495009,
     390,  379, 0x00495009,

 // properties: notify_signal_id
       0,
       2,
       1,

       0        // eod
};

static const char qt_meta_stringdata_core__Application[] = {
    "core::Application\0\0indicatorChanged()\0"
    "indexChanged()\0modulChanged()\0init()\0"
    "create(QString)\0load(QString)\0"
    "save(QString)\0,,,,,\0"
    "addIndex(QString,int,double,double,double,double)\0"
    "bool\0removeIndex(int)\0"
    "editIndex(int,QString,double,double,double,double)\0"
    ",,,\0addModule(QString,int,double,double)\0"
    "removeModule(int)\0,,\0"
    "editModule(int,QString,double)\0Indicator\0"
    "indicator\0modulGroup\0moduls\0indexGroup\0"
    "indexes\0"
};

void core::Application::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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
    }
}

const QMetaObjectExtraData core::Application::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject core::Application::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_core__Application,
      qt_meta_data_core__Application, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &core::Application::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *core::Application::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *core::Application::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_core__Application))
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
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Indicator*>(_v) = getIndicator(); break;
        case 1: *reinterpret_cast< modulGroup*>(_v) = getModuls(); break;
        case 2: *reinterpret_cast< indexGroup*>(_v) = getIndexes(); break;
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
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void core::Application::indicatorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void core::Application::indexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void core::Application::modulChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE

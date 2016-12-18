/****************************************************************************
** Meta object code from reading C++ file 'configin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "configin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_configIN[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      20,    9,    9,    9, 0x08,
      33,    9,    9,    9, 0x08,
      46,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_configIN[] = {
    "configIN\0\0Annuler()\0ParamAudio()\0"
    "ParamVideo()\0Next()\0"
};

void configIN::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        configIN *_t = static_cast<configIN *>(_o);
        switch (_id) {
        case 0: _t->Annuler(); break;
        case 1: _t->ParamAudio(); break;
        case 2: _t->ParamVideo(); break;
        case 3: _t->Next(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData configIN::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject configIN::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_configIN,
      qt_meta_data_configIN, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &configIN::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *configIN::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *configIN::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_configIN))
        return static_cast<void*>(const_cast< configIN*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int configIN::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

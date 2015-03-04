/****************************************************************************
** Meta object code from reading C++ file 'SH_MainToolBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/SH_MainToolBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SH_MainToolBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SH_MainToolBar_t {
    QByteArrayData data[6];
    char stringdata[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SH_MainToolBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SH_MainToolBar_t qt_meta_stringdata_SH_MainToolBar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SH_MainToolBar"
QT_MOC_LITERAL(1, 15, 15), // "logOffRequested"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "quitRequested"
QT_MOC_LITERAL(4, 46, 19), // "userLogOffRequested"
QT_MOC_LITERAL(5, 66, 17) // "userQuitRequested"

    },
    "SH_MainToolBar\0logOffRequested\0\0"
    "quitRequested\0userLogOffRequested\0"
    "userQuitRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SH_MainToolBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SH_MainToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SH_MainToolBar *_t = static_cast<SH_MainToolBar *>(_o);
        switch (_id) {
        case 0: _t->logOffRequested(); break;
        case 1: _t->quitRequested(); break;
        case 2: _t->userLogOffRequested(); break;
        case 3: _t->userQuitRequested(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SH_MainToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SH_MainToolBar::logOffRequested)) {
                *result = 0;
            }
        }
        {
            typedef void (SH_MainToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SH_MainToolBar::quitRequested)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SH_MainToolBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_SH_MainToolBar.data,
      qt_meta_data_SH_MainToolBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SH_MainToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SH_MainToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SH_MainToolBar.stringdata))
        return static_cast<void*>(const_cast< SH_MainToolBar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int SH_MainToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SH_MainToolBar::logOffRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SH_MainToolBar::quitRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

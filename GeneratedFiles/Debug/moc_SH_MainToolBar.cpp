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
    QByteArrayData data[16];
    char stringdata[294];
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
QT_MOC_LITERAL(4, 46, 15), // "mainViewPressed"
QT_MOC_LITERAL(5, 62, 16), // "usersViewPressed"
QT_MOC_LITERAL(6, 79, 18), // "projectViewPressed"
QT_MOC_LITERAL(7, 98, 19), // "calendarViewPressed"
QT_MOC_LITERAL(8, 118, 17), // "clientViewPressed"
QT_MOC_LITERAL(9, 136, 19), // "userLogOffRequested"
QT_MOC_LITERAL(10, 156, 17), // "userQuitRequested"
QT_MOC_LITERAL(11, 174, 21), // "userMainViewRequested"
QT_MOC_LITERAL(12, 196, 22), // "userUsersViewRequested"
QT_MOC_LITERAL(13, 219, 24), // "userProjectViewRequested"
QT_MOC_LITERAL(14, 244, 25), // "userCalendarViewRequested"
QT_MOC_LITERAL(15, 270, 23) // "userClientViewRequested"

    },
    "SH_MainToolBar\0logOffRequested\0\0"
    "quitRequested\0mainViewPressed\0"
    "usersViewPressed\0projectViewPressed\0"
    "calendarViewPressed\0clientViewPressed\0"
    "userLogOffRequested\0userQuitRequested\0"
    "userMainViewRequested\0userUsersViewRequested\0"
    "userProjectViewRequested\0"
    "userCalendarViewRequested\0"
    "userClientViewRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SH_MainToolBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    0,   88,    2, 0x06 /* Public */,
       7,    0,   89,    2, 0x06 /* Public */,
       8,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 2: _t->mainViewPressed(); break;
        case 3: _t->usersViewPressed(); break;
        case 4: _t->projectViewPressed(); break;
        case 5: _t->calendarViewPressed(); break;
        case 6: _t->clientViewPressed(); break;
        case 7: _t->userLogOffRequested(); break;
        case 8: _t->userQuitRequested(); break;
        case 9: _t->userMainViewRequested(); break;
        case 10: _t->userUsersViewRequested(); break;
        case 11: _t->userProjectViewRequested(); break;
        case 12: _t->userCalendarViewRequested(); break;
        case 13: _t->userClientViewRequested(); break;
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
        {
            typedef void (SH_MainToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SH_MainToolBar::mainViewPressed)) {
                *result = 2;
            }
        }
        {
            typedef void (SH_MainToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SH_MainToolBar::usersViewPressed)) {
                *result = 3;
            }
        }
        {
            typedef void (SH_MainToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SH_MainToolBar::projectViewPressed)) {
                *result = 4;
            }
        }
        {
            typedef void (SH_MainToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SH_MainToolBar::calendarViewPressed)) {
                *result = 5;
            }
        }
        {
            typedef void (SH_MainToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SH_MainToolBar::clientViewPressed)) {
                *result = 6;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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

// SIGNAL 2
void SH_MainToolBar::mainViewPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void SH_MainToolBar::usersViewPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void SH_MainToolBar::projectViewPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void SH_MainToolBar::calendarViewPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void SH_MainToolBar::clientViewPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

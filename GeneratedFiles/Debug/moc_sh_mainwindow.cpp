/****************************************************************************
** Meta object code from reading C++ file 'sh_mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/sh_mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sh_mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SH_MainWindow_t {
    QByteArrayData data[12];
    char stringdata[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SH_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SH_MainWindow_t qt_meta_stringdata_SH_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SH_MainWindow"
QT_MOC_LITERAL(1, 14, 24), // "usersTreeViewClickedItem"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5), // "index"
QT_MOC_LITERAL(4, 46, 15), // "quitApplication"
QT_MOC_LITERAL(5, 62, 19), // "userRequestedLogOff"
QT_MOC_LITERAL(6, 82, 26), // "mainToolBarMainViewPressed"
QT_MOC_LITERAL(7, 109, 29), // "mainToolBarProjectViewPressed"
QT_MOC_LITERAL(8, 139, 27), // "mainToolBarUsersViewPressed"
QT_MOC_LITERAL(9, 167, 30), // "mainToolBarCalendarViewPressed"
QT_MOC_LITERAL(10, 198, 28), // "mainToolBarClientViewPressed"
QT_MOC_LITERAL(11, 227, 20) // "usersTreeClickedItem"

    },
    "SH_MainWindow\0usersTreeViewClickedItem\0"
    "\0index\0quitApplication\0userRequestedLogOff\0"
    "mainToolBarMainViewPressed\0"
    "mainToolBarProjectViewPressed\0"
    "mainToolBarUsersViewPressed\0"
    "mainToolBarCalendarViewPressed\0"
    "mainToolBarClientViewPressed\0"
    "usersTreeClickedItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SH_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    3,

       0        // eod
};

void SH_MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SH_MainWindow *_t = static_cast<SH_MainWindow *>(_o);
        switch (_id) {
        case 0: _t->usersTreeViewClickedItem((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->quitApplication(); break;
        case 2: _t->userRequestedLogOff(); break;
        case 3: _t->mainToolBarMainViewPressed(); break;
        case 4: _t->mainToolBarProjectViewPressed(); break;
        case 5: _t->mainToolBarUsersViewPressed(); break;
        case 6: _t->mainToolBarCalendarViewPressed(); break;
        case 7: _t->mainToolBarClientViewPressed(); break;
        case 8: _t->usersTreeClickedItem((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SH_MainWindow::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SH_MainWindow::usersTreeViewClickedItem)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SH_MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SH_MainWindow.data,
      qt_meta_data_SH_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SH_MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SH_MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SH_MainWindow.stringdata))
        return static_cast<void*>(const_cast< SH_MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SH_MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SH_MainWindow::usersTreeViewClickedItem(QModelIndex _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

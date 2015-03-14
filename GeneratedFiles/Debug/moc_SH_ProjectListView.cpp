/****************************************************************************
** Meta object code from reading C++ file 'SH_ProjectListView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/SH_ProjectListView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SH_ProjectListView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SH_ProjectListView_t {
    QByteArrayData data[7];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SH_ProjectListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SH_ProjectListView_t qt_meta_stringdata_SH_ProjectListView = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SH_ProjectListView"
QT_MOC_LITERAL(1, 19, 17), // "addProjectClicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 20), // "deleteProjectClicked"
QT_MOC_LITERAL(4, 59, 16), // "contextMenuEvent"
QT_MOC_LITERAL(5, 76, 18), // "QContextMenuEvent*"
QT_MOC_LITERAL(6, 95, 5) // "event"

    },
    "SH_ProjectListView\0addProjectClicked\0"
    "\0deleteProjectClicked\0contextMenuEvent\0"
    "QContextMenuEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SH_ProjectListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void SH_ProjectListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SH_ProjectListView *_t = static_cast<SH_ProjectListView *>(_o);
        switch (_id) {
        case 0: _t->addProjectClicked(); break;
        case 1: _t->deleteProjectClicked(); break;
        case 2: _t->contextMenuEvent((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SH_ProjectListView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_SH_ProjectListView.data,
      qt_meta_data_SH_ProjectListView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SH_ProjectListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SH_ProjectListView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SH_ProjectListView.stringdata))
        return static_cast<void*>(const_cast< SH_ProjectListView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int SH_ProjectListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'mycontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Charts/mycontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mycontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyController_t {
    QByteArrayData data[17];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyController_t qt_meta_stringdata_MyController = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyController"
QT_MOC_LITERAL(1, 13, 11), // "newBarChart"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "onCellChanged"
QT_MOC_LITERAL(4, 40, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(5, 58, 4), // "item"
QT_MOC_LITERAL(6, 63, 8), // "openFile"
QT_MOC_LITERAL(7, 72, 8), // "saveFile"
QT_MOC_LITERAL(8, 81, 6), // "addRow"
QT_MOC_LITERAL(9, 88, 9), // "addColumn"
QT_MOC_LITERAL(10, 98, 9), // "deleteRow"
QT_MOC_LITERAL(11, 108, 12), // "deleteColumn"
QT_MOC_LITERAL(12, 121, 13), // "newRadarChart"
QT_MOC_LITERAL(13, 135, 12), // "newLineChart"
QT_MOC_LITERAL(14, 148, 12), // "newAreaChart"
QT_MOC_LITERAL(15, 161, 15), // "newLineBarChart"
QT_MOC_LITERAL(16, 177, 11) // "newPieChart"

    },
    "MyController\0newBarChart\0\0onCellChanged\0"
    "QTableWidgetItem*\0item\0openFile\0"
    "saveFile\0addRow\0addColumn\0deleteRow\0"
    "deleteColumn\0newRadarChart\0newLineChart\0"
    "newAreaChart\0newLineBarChart\0newPieChart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    1,   80,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,
      15,    0,   92,    2, 0x0a /* Public */,
      16,    0,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyController *_t = static_cast<MyController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newBarChart(); break;
        case 1: _t->onCellChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->openFile(); break;
        case 3: _t->saveFile(); break;
        case 4: _t->addRow(); break;
        case 5: _t->addColumn(); break;
        case 6: _t->deleteRow(); break;
        case 7: _t->deleteColumn(); break;
        case 8: _t->newRadarChart(); break;
        case 9: _t->newLineChart(); break;
        case 10: _t->newAreaChart(); break;
        case 11: _t->newLineBarChart(); break;
        case 12: _t->newPieChart(); break;
        default: ;
        }
    }
}

const QMetaObject MyController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyController.data,
      qt_meta_data_MyController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

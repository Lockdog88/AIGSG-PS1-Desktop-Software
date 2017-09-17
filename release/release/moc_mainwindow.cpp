/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../parkingserver/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[349];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_OpenPort_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "on_ClosePort_clicked"
QT_MOC_LITERAL(4, 53, 8), // "readData"
QT_MOC_LITERAL(5, 62, 8), // "readGNSS"
QT_MOC_LITERAL(6, 71, 8), // "readPATH"
QT_MOC_LITERAL(7, 80, 4), // "data"
QT_MOC_LITERAL(8, 85, 8), // "Nmea2Dec"
QT_MOC_LITERAL(9, 94, 5), // "char*"
QT_MOC_LITERAL(10, 100, 4), // "nmea"
QT_MOC_LITERAL(11, 105, 4), // "type"
QT_MOC_LITERAL(12, 110, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(13, 143, 5), // "value"
QT_MOC_LITERAL(14, 149, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(15, 171, 29), // "on_actionMap_VIewer_triggered"
QT_MOC_LITERAL(16, 201, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(17, 223, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(18, 247, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(19, 271, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(20, 295, 29), // "on_zoomScrollBar_valueChanged"
QT_MOC_LITERAL(21, 325, 23) // "on_pushButton_5_clicked"

    },
    "MainWindow\0on_OpenPort_clicked\0\0"
    "on_ClosePort_clicked\0readData\0readGNSS\0"
    "readPATH\0data\0Nmea2Dec\0char*\0nmea\0"
    "type\0on_horizontalSlider_valueChanged\0"
    "value\0on_sendButton_clicked\0"
    "on_actionMap_VIewer_triggered\0"
    "on_pushButton_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_2_clicked\0"
    "on_zoomScrollBar_valueChanged\0"
    "on_pushButton_5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    1,   93,    2, 0x08 /* Private */,
       8,    2,   96,    2, 0x08 /* Private */,
      12,    1,  101,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,
      20,    1,  110,    2, 0x08 /* Private */,
      21,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Float, 0x80000000 | 9, QMetaType::Char,   10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_OpenPort_clicked(); break;
        case 1: _t->on_ClosePort_clicked(); break;
        case 2: _t->readData(); break;
        case 3: _t->readGNSS(); break;
        case 4: _t->readPATH((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: { float _r = _t->Nmea2Dec((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 6: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_sendButton_clicked(); break;
        case 8: _t->on_actionMap_VIewer_triggered(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_pushButton_3_clicked(); break;
        case 11: _t->on_pushButton_4_clicked(); break;
        case 12: _t->on_pushButton_2_clicked(); break;
        case 13: _t->on_zoomScrollBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

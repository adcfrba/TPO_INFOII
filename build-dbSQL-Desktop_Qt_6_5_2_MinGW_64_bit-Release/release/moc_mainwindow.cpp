/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dbSQL/mainwindow.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_pushButton_nu_clicked",
    "",
    "on_pushButton_el_clicked",
    "on_pushButton_act_clicked",
    "on_pushButton_find_clicked",
    "on_pushButton_on_clicked",
    "on_pushButton_off_clicked",
    "deviceDiscovered",
    "QBluetoothDeviceInfo",
    "info",
    "on_listWidget_itemClicked",
    "QListWidgetItem*",
    "item",
    "attemptConnection"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[11];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[26];
    char stringdata5[27];
    char stringdata6[25];
    char stringdata7[26];
    char stringdata8[17];
    char stringdata9[21];
    char stringdata10[5];
    char stringdata11[26];
    char stringdata12[17];
    char stringdata13[5];
    char stringdata14[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 24),  // "on_pushButton_nu_clicked"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 24),  // "on_pushButton_el_clicked"
        QT_MOC_LITERAL(62, 25),  // "on_pushButton_act_clicked"
        QT_MOC_LITERAL(88, 26),  // "on_pushButton_find_clicked"
        QT_MOC_LITERAL(115, 24),  // "on_pushButton_on_clicked"
        QT_MOC_LITERAL(140, 25),  // "on_pushButton_off_clicked"
        QT_MOC_LITERAL(166, 16),  // "deviceDiscovered"
        QT_MOC_LITERAL(183, 20),  // "QBluetoothDeviceInfo"
        QT_MOC_LITERAL(204, 4),  // "info"
        QT_MOC_LITERAL(209, 25),  // "on_listWidget_itemClicked"
        QT_MOC_LITERAL(235, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(252, 4),  // "item"
        QT_MOC_LITERAL(257, 17)   // "attemptConnection"
    },
    "MainWindow",
    "on_pushButton_nu_clicked",
    "",
    "on_pushButton_el_clicked",
    "on_pushButton_act_clicked",
    "on_pushButton_find_clicked",
    "on_pushButton_on_clicked",
    "on_pushButton_off_clicked",
    "deviceDiscovered",
    "QBluetoothDeviceInfo",
    "info",
    "on_listWidget_itemClicked",
    "QListWidgetItem*",
    "item",
    "attemptConnection"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    1,   74,    2, 0x08,    7 /* Private */,
      11,    1,   77,    2, 0x08,    9 /* Private */,
      14,    0,   80,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_pushButton_nu_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_el_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_act_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_find_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_on_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_off_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deviceDiscovered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBluetoothDeviceInfo &, std::false_type>,
        // method 'on_listWidget_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'attemptConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_nu_clicked(); break;
        case 1: _t->on_pushButton_el_clicked(); break;
        case 2: _t->on_pushButton_act_clicked(); break;
        case 3: _t->on_pushButton_find_clicked(); break;
        case 4: _t->on_pushButton_on_clicked(); break;
        case 5: _t->on_pushButton_off_clicked(); break;
        case 6: _t->deviceDiscovered((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceInfo>>(_a[1]))); break;
        case 7: _t->on_listWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 8: _t->attemptConnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothDeviceInfo >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP

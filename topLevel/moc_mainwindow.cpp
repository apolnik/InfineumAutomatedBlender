/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ConsoleTest/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      84,   76,   11,   11, 0x08,
     120,   11,   11,   11, 0x08,
     144,   11,   11,   11, 0x08,
     168,   11,   11,   11, 0x08,
     196,  189,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     261,  189,   11,   11, 0x08,
     295,   11,   11,   11, 0x08,
     326,  189,   11,   11, 0x08,
     360,   11,   11,   11, 0x08,
     391,  189,   11,   11, 0x08,
     425,   11,   11,   11, 0x08,
     456,  189,   11,   11, 0x08,
     490,   11,   11,   11, 0x08,
     521,  189,   11,   11, 0x08,
     555,   11,   11,   11, 0x08,
     586,  189,   11,   11, 0x08,
     620,   11,   11,   11, 0x08,
     651,  189,   11,   11, 0x08,
     685,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pump1Btn_clicked()\0"
    "on_pump2Btn_clicked()\0on_clnBtn_clicked()\0"
    "min,max\0on_linearRail_rangeChanged(int,int)\0"
    "on_config_run_clicked()\0on_run_preset_clicked()\0"
    "on_stopBtn_clicked()\0action\0"
    "on_dial_hot1_actionTriggered(int)\0"
    "on_spin_hot1_editingFinished()\0"
    "on_dial_mix1_actionTriggered(int)\0"
    "on_spin_mix1_editingFinished()\0"
    "on_dial_hot2_actionTriggered(int)\0"
    "on_spin_hot2_editingFinished()\0"
    "on_dial_mix2_actionTriggered(int)\0"
    "on_spin_mix2_editingFinished()\0"
    "on_dial_hot3_actionTriggered(int)\0"
    "on_spin_hot3_editingFinished()\0"
    "on_dial_mix3_actionTriggered(int)\0"
    "on_spin_mix3_editingFinished()\0"
    "on_dial_hot4_actionTriggered(int)\0"
    "on_spin_hot4_editingFinished()\0"
    "on_dial_mix4_actionTriggered(int)\0"
    "on_spin_mix4_editingFinished()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {

        case 0: _t->on_config_run_clicked(); break;
        case 1: _t->on_run_preset_clicked(); break;
        case 2: _t->on_stopBtn_clicked(); break;
        case 3: _t->on_dial_hot1_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spin_hot1_editingFinished(); break;
        case 5: _t->on_dial_mix1_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_spin_mix1_editingFinished(); break;
        case 7: _t->on_dial_hot2_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_spin_hot2_editingFinished(); break;
        case 9: _t->on_dial_mix2_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_spin_mix2_editingFinished(); break;
        case 11: _t->on_dial_hot3_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_spin_hot3_editingFinished(); break;
        case 13: _t->on_dial_mix3_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_spin_mix3_editingFinished(); break;
        case 15: _t->on_dial_hot4_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_spin_hot4_editingFinished(); break;
        case 17: _t->on_dial_mix4_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_spin_mix4_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

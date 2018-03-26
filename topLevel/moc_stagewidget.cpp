/****************************************************************************
** Meta object code from reading C++ file 'stagewidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ConsoleTest/stagewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stagewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StageWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      44,   39,   12,   12, 0x08,
      73,   39,   12,   12, 0x08,
     109,   39,   12,   12, 0x08,
     146,   39,   12,   12, 0x08,
     176,   39,   12,   12, 0x08,
     214,   39,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StageWidget[] = {
    "StageWidget\0\0on_deleteButton_clicked()\0"
    "arg1\0on_spinBox_valueChanged(int)\0"
    "on_mixtimeSpin_valueChanged(double)\0"
    "on_heattimeSpin_valueChanged(double)\0"
    "on_tempSpin_valueChanged(int)\0"
    "on_fluidamntSpin_valueChanged(double)\0"
    "on_fluidnameEdit_textChanged(QString)\0"
};

void StageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StageWidget *_t = static_cast<StageWidget *>(_o);
        switch (_id) {
        case 0: _t->on_deleteButton_clicked(); break;
        case 1: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_mixtimeSpin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_heattimeSpin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_tempSpin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_fluidamntSpin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_fluidnameEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StageWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StageWidget,
      qt_meta_data_StageWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StageWidget))
        return static_cast<void*>(const_cast< StageWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int StageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'warpsettingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GaussianSmooth/warpsettingsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'warpsettingsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WarpSettingsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WarpSettingsDialog[] = {
    "WarpSettingsDialog\0\0x,y\0"
    "wrap_triggered(warpparams,warpparams)\0"
    "on_buttonBox_accepted()\0"
};

void WarpSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WarpSettingsDialog *_t = static_cast<WarpSettingsDialog *>(_o);
        switch (_id) {
        case 0: _t->wrap_triggered((*reinterpret_cast< warpparams(*)>(_a[1])),(*reinterpret_cast< warpparams(*)>(_a[2]))); break;
        case 1: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WarpSettingsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WarpSettingsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WarpSettingsDialog,
      qt_meta_data_WarpSettingsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WarpSettingsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WarpSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WarpSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WarpSettingsDialog))
        return static_cast<void*>(const_cast< WarpSettingsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int WarpSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WarpSettingsDialog::wrap_triggered(warpparams _t1, warpparams _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

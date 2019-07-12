/****************************************************************************
** Meta object code from reading C++ file 'gtd.h'
**
** Created: Wed 17. Feb 23:39:35 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gtd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gtd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GTD[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      26,    4,    4,    4, 0x0a,
      45,    4,    4,    4, 0x0a,
      78,   67,    4,    4, 0x0a,
     108,   67,    4,    4, 0x0a,
     144,    4,    4,    4, 0x0a,
     166,    4,    4,    4, 0x0a,
     193,    4,    4,    4, 0x0a,
     231,  226,    4,    4, 0x0a,
     269,  264,    4,    4, 0x0a,
     323,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GTD[] = {
    "GTD\0\0on_Aceptar_clicked()\0on_Nuevo_clicked()\0"
    "on_Cancelar_clicked()\0row,column\0"
    "on_Tabla_cellClicked(int,int)\0"
    "on_Tabla_cellDoubleClicked(int,int)\0"
    "on_Eliminar_clicked()\0on_Fecha_Entrada_clicked()\0"
    "on_Calendario_selectionChanged()\0text\0"
    "on_Busqueda_textChanged(QString)\0item\0"
    "on_Lista_Busqueda_itemDoubleClicked(QListWidgetItem*)\0"
    "cambio()\0"
};

void GTD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GTD *_t = static_cast<GTD *>(_o);
        switch (_id) {
        case 0: _t->on_Aceptar_clicked(); break;
        case 1: _t->on_Nuevo_clicked(); break;
        case 2: _t->on_Cancelar_clicked(); break;
        case 3: _t->on_Tabla_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_Tabla_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_Eliminar_clicked(); break;
        case 6: _t->on_Fecha_Entrada_clicked(); break;
        case 7: _t->on_Calendario_selectionChanged(); break;
        case 8: _t->on_Busqueda_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_Lista_Busqueda_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->cambio(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GTD::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GTD::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GTD,
      qt_meta_data_GTD, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GTD::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GTD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GTD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GTD))
        return static_cast<void*>(const_cast< GTD*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GTD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

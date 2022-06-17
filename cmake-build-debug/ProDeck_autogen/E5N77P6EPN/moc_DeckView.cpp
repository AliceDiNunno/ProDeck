/****************************************************************************
** Meta object code from reading C++ file 'DeckView.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/OS/DeckView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeckView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeckView_t {
    const uint offsetsAndSize[10];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DeckView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DeckView_t qt_meta_stringdata_DeckView = {
    {
QT_MOC_LITERAL(0, 8), // "DeckView"
QT_MOC_LITERAL(9, 10), // "refreshKey"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 5), // "index"
QT_MOC_LITERAL(27, 3) // "key"

    },
    "DeckView\0refreshKey\0\0index\0key"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeckView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    3,    4,

       0        // eod
};

void DeckView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeckView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refreshKey((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeckView::*)(int , QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeckView::refreshKey)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DeckView::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DeckView.offsetsAndSize,
    qt_meta_data_DeckView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DeckView_t
, QtPrivate::TypeAndForceComplete<DeckView, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>



>,
    nullptr
} };


const QMetaObject *DeckView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeckView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeckView.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeckView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void DeckView::refreshKey(int _t1, QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 't_finder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../t_finder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't_finder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TFinder_t {
    QByteArrayData data[16];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TFinder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TFinder_t qt_meta_stringdata_TFinder = {
    {
QT_MOC_LITERAL(0, 0, 7), // "TFinder"
QT_MOC_LITERAL(1, 8, 13), // "appendToModel"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "fileModel"
QT_MOC_LITERAL(4, 33, 13), // "setFinderTime"
QT_MOC_LITERAL(5, 47, 5), // "timer"
QT_MOC_LITERAL(6, 53, 15), // "getSearchParams"
QT_MOC_LITERAL(7, 69, 9), // "directory"
QT_MOC_LITERAL(8, 79, 4), // "text"
QT_MOC_LITERAL(9, 84, 4), // "find"
QT_MOC_LITERAL(10, 89, 14), // "openFileOfItem"
QT_MOC_LITERAL(11, 104, 8), // "fileName"
QT_MOC_LITERAL(12, 113, 3), // "row"
QT_MOC_LITERAL(13, 117, 10), // "isOpenFile"
QT_MOC_LITERAL(14, 128, 7), // "setStop"
QT_MOC_LITERAL(15, 136, 6) // "isStop"

    },
    "TFinder\0appendToModel\0\0fileModel\0"
    "setFinderTime\0timer\0getSearchParams\0"
    "directory\0text\0find\0openFileOfItem\0"
    "fileName\0row\0isOpenFile\0setStop\0isStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TFinder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   50,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,
      10,    3,   56,    2, 0x0a /* Public */,
      14,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   11,   12,   13,
    QMetaType::Void, QMetaType::QVariant,   15,

       0        // eod
};

void TFinder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TFinder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appendToModel((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->setFinderTime((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->getSearchParams((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 3: _t->find(); break;
        case 4: _t->openFileOfItem((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3]))); break;
        case 5: _t->setStop((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TFinder::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TFinder::appendToModel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TFinder::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TFinder::setFinderTime)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TFinder::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TFinder.data,
    qt_meta_data_TFinder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TFinder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TFinder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TFinder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TFinder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TFinder::appendToModel(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TFinder::setFinderTime(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

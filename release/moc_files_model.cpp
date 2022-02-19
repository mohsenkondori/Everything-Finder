/****************************************************************************
** Meta object code from reading C++ file 'files_model.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../files_model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'files_model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilesModel_t {
    QByteArrayData data[13];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilesModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilesModel_t qt_meta_stringdata_FilesModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FilesModel"
QT_MOC_LITERAL(1, 11, 3), // "get"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 3), // "row"
QT_MOC_LITERAL(4, 20, 6), // "append"
QT_MOC_LITERAL(5, 27, 8), // "fileName"
QT_MOC_LITERAL(6, 36, 4), // "path"
QT_MOC_LITERAL(7, 41, 4), // "size"
QT_MOC_LITERAL(8, 46, 9), // "removeAll"
QT_MOC_LITERAL(9, 56, 8), // "FileRole"
QT_MOC_LITERAL(10, 65, 12), // "FileNameRole"
QT_MOC_LITERAL(11, 78, 8), // "PathRole"
QT_MOC_LITERAL(12, 87, 8) // "SizeRole"

    },
    "FilesModel\0get\0\0row\0append\0fileName\0"
    "path\0size\0removeAll\0FileRole\0FileNameRole\0"
    "PathRole\0SizeRole"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilesModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       1,   40, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x02 /* Public */,
       4,    3,   32,    2, 0x02 /* Public */,
       8,    0,   39,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QVariantMap, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       9,    9, 0x0,    3,   45,

 // enum data: key, value
      10, uint(FilesModel::FileNameRole),
      11, uint(FilesModel::PathRole),
      12, uint(FilesModel::SizeRole),

       0        // eod
};

void FilesModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilesModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariantMap _r = _t->get((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->append((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->removeAll(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FilesModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_FilesModel.data,
    qt_meta_data_FilesModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilesModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilesModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilesModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int FilesModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

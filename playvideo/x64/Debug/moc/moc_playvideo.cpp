/****************************************************************************
** Meta object code from reading C++ file 'playvideo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../playvideo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playvideo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayVideo_t {
    QByteArrayData data[20];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayVideo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayVideo_t qt_meta_stringdata_PlayVideo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PlayVideo"
QT_MOC_LITERAL(1, 10, 7), // "openVid"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 31, 5), // "index"
QT_MOC_LITERAL(5, 37, 9), // "openAudio"
QT_MOC_LITERAL(6, 47, 7), // "playVid"
QT_MOC_LITERAL(7, 55, 10), // "soundClick"
QT_MOC_LITERAL(8, 66, 9), // "soundPlay"
QT_MOC_LITERAL(9, 76, 5), // "value"
QT_MOC_LITERAL(10, 82, 12), // "timeDuration"
QT_MOC_LITERAL(11, 95, 12), // "timePosition"
QT_MOC_LITERAL(12, 108, 11), // "skipForward"
QT_MOC_LITERAL(13, 120, 12), // "skipBackward"
QT_MOC_LITERAL(14, 133, 6), // "addTab"
QT_MOC_LITERAL(15, 140, 9), // "removeTab"
QT_MOC_LITERAL(16, 150, 7), // "addLink"
QT_MOC_LITERAL(17, 158, 10), // "deleteLink"
QT_MOC_LITERAL(18, 169, 10), // "backBtnadd"
QT_MOC_LITERAL(19, 180, 13) // "backBtndelete"

    },
    "PlayVideo\0openVid\0\0QModelIndex\0index\0"
    "openAudio\0playVid\0soundClick\0soundPlay\0"
    "value\0timeDuration\0timePosition\0"
    "skipForward\0skipBackward\0addTab\0"
    "removeTab\0addLink\0deleteLink\0backBtnadd\0"
    "backBtndelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayVideo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x0a /* Public */,
       5,    1,   92,    2, 0x0a /* Public */,
       6,    0,   95,    2, 0x0a /* Public */,
       7,    0,   96,    2, 0x0a /* Public */,
       8,    1,   97,    2, 0x0a /* Public */,
      10,    1,  100,    2, 0x0a /* Public */,
      11,    1,  103,    2, 0x0a /* Public */,
      12,    1,  106,    2, 0x0a /* Public */,
      13,    1,  109,    2, 0x0a /* Public */,
      14,    0,  112,    2, 0x0a /* Public */,
      15,    0,  113,    2, 0x0a /* Public */,
      16,    0,  114,    2, 0x0a /* Public */,
      17,    1,  115,    2, 0x0a /* Public */,
      18,    0,  118,    2, 0x0a /* Public */,
      19,    0,  119,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayVideo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayVideo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openVid((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->openAudio((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->playVid(); break;
        case 3: _t->soundClick(); break;
        case 4: _t->soundPlay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->timeDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->timePosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->skipForward((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->skipBackward((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->addTab(); break;
        case 10: _t->removeTab(); break;
        case 11: _t->addLink(); break;
        case 12: _t->deleteLink((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->backBtnadd(); break;
        case 14: _t->backBtndelete(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlayVideo::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_PlayVideo.data,
    qt_meta_data_PlayVideo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlayVideo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayVideo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayVideo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PlayVideo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

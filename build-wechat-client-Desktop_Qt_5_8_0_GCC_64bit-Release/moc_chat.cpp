/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wechat-client/chat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_chat_t {
    QByteArrayData data[15];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chat_t qt_meta_stringdata_chat = {
    {
QT_MOC_LITERAL(0, 0, 4), // "chat"
QT_MOC_LITERAL(1, 5, 4), // "exit"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 8), // "send_msg"
QT_MOC_LITERAL(4, 20, 16), // "update_chat_name"
QT_MOC_LITERAL(5, 37, 14), // "send_file_name"
QT_MOC_LITERAL(6, 52, 9), // "send_file"
QT_MOC_LITERAL(7, 62, 10), // "ready_chat"
QT_MOC_LITERAL(8, 73, 19), // "on_exit_btn_clicked"
QT_MOC_LITERAL(9, 93, 8), // "chat_ing"
QT_MOC_LITERAL(10, 102, 19), // "on_send_btn_clicked"
QT_MOC_LITERAL(11, 122, 24), // "on_open_file_btn_clicked"
QT_MOC_LITERAL(12, 147, 24), // "on_send_file_btn_clicked"
QT_MOC_LITERAL(13, 172, 16), // "updClintProgress"
QT_MOC_LITERAL(14, 189, 9) // "open_fail"

    },
    "chat\0exit\0\0send_msg\0update_chat_name\0"
    "send_file_name\0send_file\0ready_chat\0"
    "on_exit_btn_clicked\0chat_ing\0"
    "on_send_btn_clicked\0on_open_file_btn_clicked\0"
    "on_send_file_btn_clicked\0updClintProgress\0"
    "open_fail"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       4,    1,   83,    2, 0x06 /* Public */,
       5,    1,   86,    2, 0x06 /* Public */,
       6,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   92,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    1,   96,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    2,  102,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void,

       0        // eod
};

void chat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chat *_t = static_cast<chat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exit(); break;
        case 1: _t->send_msg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->update_chat_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->send_file_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->send_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->ready_chat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_exit_btn_clicked(); break;
        case 7: _t->chat_ing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_send_btn_clicked(); break;
        case 9: _t->on_open_file_btn_clicked(); break;
        case 10: _t->on_send_file_btn_clicked(); break;
        case 11: _t->updClintProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 12: _t->open_fail(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (chat::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chat::exit)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (chat::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chat::send_msg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (chat::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chat::update_chat_name)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (chat::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chat::send_file_name)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (chat::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chat::send_file)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject chat::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_chat.data,
      qt_meta_data_chat,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chat::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chat.stringdata0))
        return static_cast<void*>(const_cast< chat*>(this));
    return QWidget::qt_metacast(_clname);
}

int chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void chat::exit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void chat::send_msg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void chat::update_chat_name(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void chat::send_file_name(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void chat::send_file(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

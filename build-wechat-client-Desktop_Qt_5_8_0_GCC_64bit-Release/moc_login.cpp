/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wechat-client/login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_login_t {
    QByteArrayData data[17];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_login_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_login_t qt_meta_stringdata_login = {
    {
QT_MOC_LITERAL(0, 0, 5), // "login"
QT_MOC_LITERAL(1, 6, 13), // "login_success"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "update_data"
QT_MOC_LITERAL(4, 33, 11), // "receive_msg"
QT_MOC_LITERAL(5, 45, 7), // "add_res"
QT_MOC_LITERAL(6, 53, 10), // "show_flist"
QT_MOC_LITERAL(7, 64, 20), // "on_login_btn_clicked"
QT_MOC_LITERAL(8, 85, 18), // "on_reg_btn_clicked"
QT_MOC_LITERAL(9, 104, 11), // "readMessage"
QT_MOC_LITERAL(10, 116, 13), // "receiveupdate"
QT_MOC_LITERAL(11, 130, 8), // "msg_send"
QT_MOC_LITERAL(12, 139, 16), // "update_chat_name"
QT_MOC_LITERAL(13, 156, 10), // "erase_name"
QT_MOC_LITERAL(14, 167, 11), // "update_name"
QT_MOC_LITERAL(15, 179, 18), // "friend_list_update"
QT_MOC_LITERAL(16, 198, 10) // "friend_add"

    },
    "login\0login_success\0\0update_data\0"
    "receive_msg\0add_res\0show_flist\0"
    "on_login_btn_clicked\0on_reg_btn_clicked\0"
    "readMessage\0receiveupdate\0msg_send\0"
    "update_chat_name\0erase_name\0update_name\0"
    "friend_list_update\0friend_add"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_login[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    1,   90,    2, 0x06 /* Public */,
       4,    1,   93,    2, 0x06 /* Public */,
       5,    1,   96,    2, 0x06 /* Public */,
       6,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  102,    2, 0x08 /* Private */,
       8,    0,  103,    2, 0x08 /* Private */,
       9,    0,  104,    2, 0x08 /* Private */,
      10,    0,  105,    2, 0x08 /* Private */,
      11,    1,  106,    2, 0x08 /* Private */,
      12,    1,  109,    2, 0x08 /* Private */,
      13,    0,  112,    2, 0x08 /* Private */,
      14,    1,  113,    2, 0x08 /* Private */,
      15,    0,  116,    2, 0x08 /* Private */,
      16,    1,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        login *_t = static_cast<login *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->login_success(); break;
        case 1: _t->update_data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->receive_msg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->add_res((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->show_flist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_login_btn_clicked(); break;
        case 6: _t->on_reg_btn_clicked(); break;
        case 7: _t->readMessage(); break;
        case 8: _t->receiveupdate(); break;
        case 9: _t->msg_send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->update_chat_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->erase_name(); break;
        case 12: _t->update_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->friend_list_update(); break;
        case 14: _t->friend_add((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (login::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&login::login_success)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (login::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&login::update_data)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (login::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&login::receive_msg)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (login::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&login::add_res)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (login::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&login::show_flist)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject login::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_login.data,
      qt_meta_data_login,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *login::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_login.stringdata0))
        return static_cast<void*>(const_cast< login*>(this));
    return QWidget::qt_metacast(_clname);
}

int login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void login::login_success()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void login::update_data(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void login::receive_msg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void login::add_res(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void login::show_flist(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

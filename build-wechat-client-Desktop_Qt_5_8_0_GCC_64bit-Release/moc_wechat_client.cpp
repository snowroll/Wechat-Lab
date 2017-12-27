/****************************************************************************
** Meta object code from reading C++ file 'wechat_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wechat-client/wechat_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wechat_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_wechat_client_t {
    QByteArrayData data[12];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wechat_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wechat_client_t qt_meta_stringdata_wechat_client = {
    {
QT_MOC_LITERAL(0, 0, 13), // "wechat_client"
QT_MOC_LITERAL(1, 14, 11), // "update_list"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "chat_begin"
QT_MOC_LITERAL(4, 38, 10), // "add_friend"
QT_MOC_LITERAL(5, 49, 12), // "receivelogin"
QT_MOC_LITERAL(6, 62, 21), // "on_update_btn_clicked"
QT_MOC_LITERAL(7, 84, 11), // "readyupdate"
QT_MOC_LITERAL(8, 96, 6), // "reshow"
QT_MOC_LITERAL(9, 103, 19), // "on_chat_btn_clicked"
QT_MOC_LITERAL(10, 123, 7), // "res_add"
QT_MOC_LITERAL(11, 131, 18) // "on_add_btn_clicked"

    },
    "wechat_client\0update_list\0\0chat_begin\0"
    "add_friend\0receivelogin\0on_update_btn_clicked\0"
    "readyupdate\0reshow\0on_chat_btn_clicked\0"
    "res_add\0on_add_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wechat_client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       4,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   71,    2, 0x08 /* Private */,
       6,    0,   72,    2, 0x08 /* Private */,
       7,    1,   73,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void wechat_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        wechat_client *_t = static_cast<wechat_client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_list(); break;
        case 1: _t->chat_begin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->add_friend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->receivelogin(); break;
        case 4: _t->on_update_btn_clicked(); break;
        case 5: _t->readyupdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->reshow(); break;
        case 7: _t->on_chat_btn_clicked(); break;
        case 8: _t->res_add((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_add_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (wechat_client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wechat_client::update_list)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (wechat_client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wechat_client::chat_begin)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (wechat_client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wechat_client::add_friend)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject wechat_client::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_wechat_client.data,
      qt_meta_data_wechat_client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *wechat_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wechat_client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_wechat_client.stringdata0))
        return static_cast<void*>(const_cast< wechat_client*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int wechat_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void wechat_client::update_list()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void wechat_client::chat_begin(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void wechat_client::add_friend(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

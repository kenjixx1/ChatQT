/****************************************************************************
** Meta object code from reading C++ file 'ChatGui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../ChatGui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChatGui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatGui_t {
    QByteArrayData data[14];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatGui_t qt_meta_stringdata_ChatGui = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ChatGui"
QT_MOC_LITERAL(1, 8, 26), // "on_CreateNewButton_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 18), // "ActiveButton_Click"
QT_MOC_LITERAL(4, 55, 23), // "on_DeleteButton_clicked"
QT_MOC_LITERAL(5, 79, 11), // "ClearLayout"
QT_MOC_LITERAL(6, 91, 8), // "QLayout*"
QT_MOC_LITERAL(7, 100, 6), // "layout"
QT_MOC_LITERAL(8, 107, 15), // "LoadChatHistory"
QT_MOC_LITERAL(9, 123, 21), // "on_SendButton_clicked"
QT_MOC_LITERAL(10, 145, 10), // "AddMessage"
QT_MOC_LITERAL(11, 156, 7), // "message"
QT_MOC_LITERAL(12, 164, 6), // "sender"
QT_MOC_LITERAL(13, 171, 23) // "on_RenameButton_clicked"

    },
    "ChatGui\0on_CreateNewButton_clicked\0\0"
    "ActiveButton_Click\0on_DeleteButton_clicked\0"
    "ClearLayout\0QLayout*\0layout\0LoadChatHistory\0"
    "on_SendButton_clicked\0AddMessage\0"
    "message\0sender\0on_RenameButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatGui[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    2,   62,    2, 0x08 /* Private */,
      13,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   11,   12,
    QMetaType::Void,

       0        // eod
};

void ChatGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_CreateNewButton_clicked(); break;
        case 1: _t->ActiveButton_Click(); break;
        case 2: _t->on_DeleteButton_clicked(); break;
        case 3: _t->ClearLayout((*reinterpret_cast< QLayout*(*)>(_a[1]))); break;
        case 4: _t->LoadChatHistory(); break;
        case 5: _t->on_SendButton_clicked(); break;
        case 6: _t->AddMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->on_RenameButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatGui::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_ChatGui.data,
    qt_meta_data_ChatGui,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatGui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatGui.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ChatGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

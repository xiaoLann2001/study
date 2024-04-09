/****************************************************************************
** Meta object code from reading C++ file 'control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../nfs_rootfs/code/path_qt_project/BalanceSerialwithSoftKey/BalanceSerial/control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Control_t {
    QByteArrayData data[15];
    char stringdata0[401];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Control_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Control_t qt_meta_stringdata_Control = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Control"
QT_MOC_LITERAL(1, 8, 13), // "handleTimeout"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 21), // "startTimerIfNotActive"
QT_MOC_LITERAL(4, 45, 24), // "stopTimerIfNoKeysPressed"
QT_MOC_LITERAL(5, 70, 34), // "on_pushButton_Move_forward_pr..."
QT_MOC_LITERAL(6, 105, 35), // "on_pushButton_Move_backward_p..."
QT_MOC_LITERAL(7, 141, 31), // "on_pushButton_Turn_left_pressed"
QT_MOC_LITERAL(8, 173, 32), // "on_pushButton_Turn_right_pressed"
QT_MOC_LITERAL(9, 206, 26), // "on_pushButton_Stop_pressed"
QT_MOC_LITERAL(10, 233, 35), // "on_pushButton_Move_forward_re..."
QT_MOC_LITERAL(11, 269, 36), // "on_pushButton_Move_backward_r..."
QT_MOC_LITERAL(12, 306, 32), // "on_pushButton_Turn_left_released"
QT_MOC_LITERAL(13, 339, 33), // "on_pushButton_Turn_right_rele..."
QT_MOC_LITERAL(14, 373, 27) // "on_pushButton_Stop_released"

    },
    "Control\0handleTimeout\0\0startTimerIfNotActive\0"
    "stopTimerIfNoKeysPressed\0"
    "on_pushButton_Move_forward_pressed\0"
    "on_pushButton_Move_backward_pressed\0"
    "on_pushButton_Turn_left_pressed\0"
    "on_pushButton_Turn_right_pressed\0"
    "on_pushButton_Stop_pressed\0"
    "on_pushButton_Move_forward_released\0"
    "on_pushButton_Move_backward_released\0"
    "on_pushButton_Turn_left_released\0"
    "on_pushButton_Turn_right_released\0"
    "on_pushButton_Stop_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Control[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Control *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleTimeout(); break;
        case 1: _t->startTimerIfNotActive(); break;
        case 2: _t->stopTimerIfNoKeysPressed(); break;
        case 3: _t->on_pushButton_Move_forward_pressed(); break;
        case 4: _t->on_pushButton_Move_backward_pressed(); break;
        case 5: _t->on_pushButton_Turn_left_pressed(); break;
        case 6: _t->on_pushButton_Turn_right_pressed(); break;
        case 7: _t->on_pushButton_Stop_pressed(); break;
        case 8: _t->on_pushButton_Move_forward_released(); break;
        case 9: _t->on_pushButton_Move_backward_released(); break;
        case 10: _t->on_pushButton_Turn_left_released(); break;
        case 11: _t->on_pushButton_Turn_right_released(); break;
        case 12: _t->on_pushButton_Stop_released(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Control::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Control.data,
    qt_meta_data_Control,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Control::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Control.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

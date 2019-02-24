/****************************************************************************
** Meta object code from reading C++ file 'walletframe.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/walletframe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'walletframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WalletFrame_t {
    QByteArrayData data[21];
    char stringdata0[324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WalletFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WalletFrame_t qt_meta_stringdata_WalletFrame = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WalletFrame"
QT_MOC_LITERAL(1, 12, 16), // "gotoOverviewPage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "gotoHistoryPage"
QT_MOC_LITERAL(4, 46, 18), // "gotoMasternodePage"
QT_MOC_LITERAL(5, 65, 20), // "gotoReceiveCoinsPage"
QT_MOC_LITERAL(6, 86, 17), // "gotoSendCoinsPage"
QT_MOC_LITERAL(7, 104, 4), // "addr"
QT_MOC_LITERAL(8, 109, 21), // "gotoBlockExplorerPage"
QT_MOC_LITERAL(9, 131, 18), // "gotoSignMessageTab"
QT_MOC_LITERAL(10, 150, 20), // "gotoVerifyMessageTab"
QT_MOC_LITERAL(11, 171, 19), // "gotoMultiSendDialog"
QT_MOC_LITERAL(12, 191, 13), // "gotoBip38Tool"
QT_MOC_LITERAL(13, 205, 13), // "encryptWallet"
QT_MOC_LITERAL(14, 219, 6), // "status"
QT_MOC_LITERAL(15, 226, 12), // "backupWallet"
QT_MOC_LITERAL(16, 239, 16), // "changePassphrase"
QT_MOC_LITERAL(17, 256, 12), // "unlockWallet"
QT_MOC_LITERAL(18, 269, 10), // "lockWallet"
QT_MOC_LITERAL(19, 280, 20), // "usedSendingAddresses"
QT_MOC_LITERAL(20, 301, 22) // "usedReceivingAddresses"

    },
    "WalletFrame\0gotoOverviewPage\0\0"
    "gotoHistoryPage\0gotoMasternodePage\0"
    "gotoReceiveCoinsPage\0gotoSendCoinsPage\0"
    "addr\0gotoBlockExplorerPage\0"
    "gotoSignMessageTab\0gotoVerifyMessageTab\0"
    "gotoMultiSendDialog\0gotoBip38Tool\0"
    "encryptWallet\0status\0backupWallet\0"
    "changePassphrase\0unlockWallet\0lockWallet\0"
    "usedSendingAddresses\0usedReceivingAddresses"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WalletFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x0a /* Public */,
       3,    0,  115,    2, 0x0a /* Public */,
       4,    0,  116,    2, 0x0a /* Public */,
       5,    0,  117,    2, 0x0a /* Public */,
       6,    1,  118,    2, 0x0a /* Public */,
       6,    0,  121,    2, 0x2a /* Public | MethodCloned */,
       8,    0,  122,    2, 0x0a /* Public */,
       9,    1,  123,    2, 0x0a /* Public */,
       9,    0,  126,    2, 0x2a /* Public | MethodCloned */,
      10,    1,  127,    2, 0x0a /* Public */,
      10,    0,  130,    2, 0x2a /* Public | MethodCloned */,
      11,    0,  131,    2, 0x0a /* Public */,
      12,    0,  132,    2, 0x0a /* Public */,
      13,    1,  133,    2, 0x0a /* Public */,
      15,    0,  136,    2, 0x0a /* Public */,
      16,    0,  137,    2, 0x0a /* Public */,
      17,    0,  138,    2, 0x0a /* Public */,
      18,    0,  139,    2, 0x0a /* Public */,
      19,    0,  140,    2, 0x0a /* Public */,
      20,    0,  141,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WalletFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WalletFrame *_t = static_cast<WalletFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gotoOverviewPage(); break;
        case 1: _t->gotoHistoryPage(); break;
        case 2: _t->gotoMasternodePage(); break;
        case 3: _t->gotoReceiveCoinsPage(); break;
        case 4: _t->gotoSendCoinsPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->gotoSendCoinsPage(); break;
        case 6: _t->gotoBlockExplorerPage(); break;
        case 7: _t->gotoSignMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->gotoSignMessageTab(); break;
        case 9: _t->gotoVerifyMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->gotoVerifyMessageTab(); break;
        case 11: _t->gotoMultiSendDialog(); break;
        case 12: _t->gotoBip38Tool(); break;
        case 13: _t->encryptWallet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->backupWallet(); break;
        case 15: _t->changePassphrase(); break;
        case 16: _t->unlockWallet(); break;
        case 17: _t->lockWallet(); break;
        case 18: _t->usedSendingAddresses(); break;
        case 19: _t->usedReceivingAddresses(); break;
        default: ;
        }
    }
}

const QMetaObject WalletFrame::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_WalletFrame.data,
      qt_meta_data_WalletFrame,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WalletFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WalletFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WalletFrame.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int WalletFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

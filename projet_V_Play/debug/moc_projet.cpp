/****************************************************************************
** Meta object code from reading C++ file 'projet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_projet_t {
    QByteArrayData data[20];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_projet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_projet_t qt_meta_stringdata_projet = {
    {
QT_MOC_LITERAL(0, 0, 6), // "projet"
QT_MOC_LITERAL(1, 7, 14), // "chargementport"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "list"
QT_MOC_LITERAL(4, 28, 17), // "envoieInfoPortCom"
QT_MOC_LITERAL(5, 46, 4), // "Text"
QT_MOC_LITERAL(6, 51, 13), // "textConnexion"
QT_MOC_LITERAL(7, 65, 8), // "testData"
QT_MOC_LITERAL(8, 74, 7), // "Donnees"
QT_MOC_LITERAL(9, 82, 11), // "gpsLatitude"
QT_MOC_LITERAL(10, 94, 9), // "ValeurLAT"
QT_MOC_LITERAL(11, 104, 10), // "ValeurLONG"
QT_MOC_LITERAL(12, 115, 7), // "timerOK"
QT_MOC_LITERAL(13, 123, 18), // "currentTextChanged"
QT_MOC_LITERAL(14, 142, 7), // "Affiche"
QT_MOC_LITERAL(15, 150, 9), // "connexion"
QT_MOC_LITERAL(16, 160, 11), // "deconnexion"
QT_MOC_LITERAL(17, 172, 8), // "lirePort"
QT_MOC_LITERAL(18, 181, 8), // "readData"
QT_MOC_LITERAL(19, 190, 8) // "emission"

    },
    "projet\0chargementport\0\0list\0"
    "envoieInfoPortCom\0Text\0textConnexion\0"
    "testData\0Donnees\0gpsLatitude\0ValeurLAT\0"
    "ValeurLONG\0timerOK\0currentTextChanged\0"
    "Affiche\0connexion\0deconnexion\0lirePort\0"
    "readData\0emission"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_projet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       7,    1,   83,    2, 0x06 /* Public */,
       9,    2,   86,    2, 0x06 /* Public */,
      12,    0,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   92,    2, 0x0a /* Public */,
      15,    0,   95,    2, 0x0a /* Public */,
      16,    0,   96,    2, 0x0a /* Public */,
      17,    0,   97,    2, 0x0a /* Public */,
      18,    0,   98,    2, 0x0a /* Public */,
      19,    0,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   10,   11,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void projet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        projet *_t = static_cast<projet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chargementport((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->envoieInfoPortCom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->textConnexion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->testData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->gpsLatitude((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 5: _t->timerOK(); break;
        case 6: _t->currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->connexion(); break;
        case 8: _t->deconnexion(); break;
        case 9: _t->lirePort(); break;
        case 10: _t->readData(); break;
        case 11: _t->emission(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (projet::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&projet::chargementport)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (projet::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&projet::envoieInfoPortCom)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (projet::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&projet::textConnexion)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (projet::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&projet::testData)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (projet::*_t)(float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&projet::gpsLatitude)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (projet::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&projet::timerOK)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject projet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_projet.data,
      qt_meta_data_projet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *projet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *projet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_projet.stringdata0))
        return static_cast<void*>(const_cast< projet*>(this));
    return QObject::qt_metacast(_clname);
}

int projet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void projet::chargementport(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void projet::envoieInfoPortCom(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void projet::textConnexion(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void projet::testData(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void projet::gpsLatitude(float _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void projet::timerOK()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

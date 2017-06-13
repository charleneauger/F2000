#ifndef PROJET_H
#define PROJET_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QStringList>
#include "basededonnees.h"

//class basededonnees;

class projet : public QObject
{
    Q_OBJECT

public:
    explicit projet(QObject *parent = 0);

   ~projet();

private:
    QSerialPort *serial;
    QSerialPortInfo *PortC;
    float ValeurX;
    float ValeurY;
    float ValeurZ;
    float ValeurLAT;
    float ValeurLONG;
    float Debit;
    float Vitesse;
    QString Text;
    QString TextData;
    QString data="";
    QStringList list;
    QString Donnees;
    basededonnees base;

signals:
     void chargementport(QStringList list);
     void envoieInfoPortCom(QString Text);
     void textConnexion(QString Text);
     void testData(QString Donnees);
     void gpsLatitude(float ValeurLAT, float ValeurLONG);
     void timerOK();
     void sendToDataBase(float ValeurLAT, float ValeurLONG, float ValeurX, float ValeurY, float ValeurZ, float Debit, float Vitesse);

public slots:
     void currentTextChanged(const QString Affiche);
     void connexion();
     void deconnexion();
     void lirePort();
     void readData();
     void emission();

};

#endif // PROJET_H

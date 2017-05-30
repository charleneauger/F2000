#include "projet.h"
#include <QDebug>
#include <QObject>
#include <QQuickItem>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QQmlApplicationEngine>
#include <QStringList>

projet::projet(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort();
}

void projet::lirePort() //Detection des ports communications.
{
    list.clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        list <<"..."<< info.portName();
        qDebug()<<list;
        emit chargementport(list);
    }
}

void projet::currentTextChanged(const QString Affiche) //Recuperation des informations concernant le port de communication
{
        PortC = new QSerialPortInfo(Affiche);
        Text = "Nom: "+PortC->portName()+"\n"+"Manufacture: "+PortC->manufacturer()+"\n"+"Description: "+PortC->description();
        emit envoieInfoPortCom(Text);
}

void projet::connexion() //connexion au port choisi
{
    serial->setPort(*PortC);
    serial->setBaudRate(9600);
    serial->open(QSerialPort::ReadWrite);
    qDebug()<< "connexion appelée";

    if(serial->isOpen())
    {
        Text = "Connexion réussie !";
        emit textConnexion(Text);
        emit timerOK();
    }
    else
    {
        Text = "La connexion a échoué ...";
        emit textConnexion(Text);
    }
}

void projet::deconnexion() //Deconnexion du port
{
    serial->close();
    Text = "Déconnexion réussie !";
    emit textConnexion(Text);
    qDebug()<< "je suis déconnectée !";

}

void projet::readData() //Lecture des donnees reçues sur le port
{
    data+=serial->readAll();
    qDebug()<<"data: "<<data;

        if (data.contains ('\n', Qt::CaseInsensitive))
        {
              TextData = data.left(data.indexOf('\n'));
              qDebug()<<"texte: "<<TextData;
              data=data.right(data.length()-data.indexOf('\n')-1);
              qDebug()<<"data: "<<data;

              QStringList List = TextData.split(',', QString::SkipEmptyParts);  //Decoupage des donnees reçues

              ValeurX = List.at(0).toFloat();
              qDebug()<<ValeurX;
              ValeurY = List.at(1).toFloat();
              qDebug()<<ValeurY;
              ValeurZ = List.at(2).toFloat();
              qDebug()<<ValeurZ;
              ValeurLAT = List.at(3).toFloat();
              qDebug()<<ValeurLAT;
              ValeurLONG = List.at(4).toFloat();
              qDebug()<<ValeurLONG;
              Debit = List.at(5).toFloat();

              emit gpsLatitude(ValeurLAT, ValeurLONG);

              Donnees = "X="+List[0]+"m/s²"+"\r\n"+"Y="+List[1]+"m/s²"+"\r\n"+"Z="+List[2]+"m/s²"+"\r\n"+"LAT="+List[3]+"\r\n"+"LONG="+List[4]+"\r\n"+"DEBIT="+List[5]+"\r\n";
              qDebug()<<Donnees;
              emit testData(Donnees);
              QCoreApplication::processEvents();
        }
}

void projet::emission()
{
    serial->write(QByteArray("1"));
    qDebug()<<"1";
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
}

projet::~projet()
{
    serial->close();
    delete serial;
    delete PortC;
}

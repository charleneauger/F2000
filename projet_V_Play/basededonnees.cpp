#include "basededonnees.h"
#include <QDebug>

basededonnees::basededonnees(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL3");
}

void basededonnees::checkConnexion()
{
    db.setHostName("localhost");
    db.setUserName("AUGER");
    db.setPassword("charlene");
    db.setDatabaseName("f2000");

    if(db.open())
    {
        qDebug() << "Vous êtes maintenant connecté à " ;
        db.close();
    }
    else
    {
        qDebug() << "La connexion a échouée, désolé :(" ;
    }

}

basededonnees::~basededonnees()
{
    db.close();
}

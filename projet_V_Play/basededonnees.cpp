#include "basededonnees.h"
//#include <QSqlQuery>
#include <QDebug>

basededonnees::basededonnees(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL3");
    Query = new QSqlQuery(db);
}

void basededonnees::checkConnexion(QString UName, QString Pass, QString DataB, QString NPort)
{
    Username = UName;
    Password = Pass;
    DataBaseName = DataB;
    port = NPort.toInt();

    db.setHostName("localhost");
    db.setUserName(Username);
    db.setPassword(Password);
    db.setDatabaseName(DataBaseName);
    db.setPort(port);

    qDebug()<<Username;
    qDebug()<<Password;
    qDebug()<<DataBaseName;
    qDebug()<<port;

    if(db.open())
    {
        Text = "Vous êtes connecté!";
        emit messageConnect(Text);
        Access=true;
        emit historique(Access);
        qDebug() << "Vous êtes maintenant connecté" ;
    }
    else
    {
        Text = "Connexion non réussi.\n Merci de bien vouloir vérifier vos champs.";
        emit messageConnect(Text);
        qDebug() << "La connexion a échouée" ;
    }
}

void basededonnees::sendtoDatabase()
{
    if(db.open())
    {
        //QSqlQuery Query(db);
        Query->prepare("INSERT INTO donnees (`LATITUDE`,`LONGITUDE`,`ACC_X`,`ACC_Y`,`ACC_Z`,`DEBIT`,`VITESSE`) VALUES ( ?, ?, ?, ?, ?, ?, ?)");
        Query->addBindValue(LATTI);
        Query->addBindValue(LONGI);
        Query->addBindValue(AX);
        Query->addBindValue(AY);
        Query->addBindValue(AZ);
        Query->addBindValue(DEB);
        Query->addBindValue(V);
        Query->exec();
        qDebug()<<"je suis passé par là!";
        qDebug()<< Query->lastError();
    }
    else
    {
        qDebug()<<"vous n'êtes pas connecté à la base de données.";
    }
}

void basededonnees::getDataToProjet(float LAT, float LONG, float X, float Y, float Z, float Deb, float VIT)
{
    LATTI=LAT;
    LONGI=LONG;
    AX=X;
    AY=Y;
    AZ=Z;
    DEB=Deb;
    V=VIT;
    emit bdd();
}

void basededonnees::dateAffiche()
{
    list.clear();
    //QSqlQuery q(db);
    Query->exec("SELECT DISTINCT DATE_FORMAT(DATE, GET_FORMAT(DATE,('EUR'))) FROM donnees");
    qDebug()<< Query->lastError();
    Query->next();
    do
    {
        list << Query->value(0).toString();
    }
     while(Query->next());
    emit listDate(list);
}

void basededonnees::afficheNameColumn()
{
    listCourbe.clear();
    //QSqlQuery query(db);
    Query->exec("SHOW COLUMNS FROM donnees;");
    qDebug()<<Query->lastError();
    Query->next();
    Query->next();
    Query->next();
    Query->next();
    do
    {
        listCourbe<<Query->value(0).toString();
    }
    while(Query->next());
    emit listNameColumn(listCourbe);
}

void basededonnees::recupValeurCombobox(QString date, QString courbe)
{
    date= "%"+date+"%";
    qDebug()<<courbe;
    if(courbe=="ACC_X")Query->prepare("SELECT  DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))), `ACC_X` FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ? ORDER BY `DATE`");
    else if (courbe=="ACC_Y")Query->prepare("SELECT  DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))), `ACC_Y` FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ? ORDER BY `DATE`");
    else if (courbe=="ACC_Z")Query->prepare("SELECT  DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))), `ACC_Z` FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ? ORDER BY `DATE`");
    else if (courbe=="DEBIT")Query->prepare("SELECT  DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))), `DEBIT` FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ? ORDER BY `DATE`");
    else if (courbe=="VITESSE")Query->prepare("SELECT  DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))), `VITESSE` FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ? ORDER BY `DATE`");
    Query->addBindValue(date);
    qDebug()<<date;
    Query->exec();
    qDebug()<< Query->lastError();
    Query->next();
    do
    {
        listaxeY<< Query->value(2).toString();
        qDebug()<<listaxeY;
    }
    while(Query->next());
    emit axeY(listaxeY);
    if(courbe=="ACC_X")Query->prepare("SELECT MAX(`ACC_X`) FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ?");
    else if (courbe=="ACC_Y")Query->prepare("SELECT MAX(`ACC_Y`) FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ?");
    else if (courbe=="ACC_Z")Query->prepare("SELECT MAX(`ACC_Z`) FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ?");
    else if (courbe=="DEBIT")Query->prepare("SELECT MAX(`DEBIT`) FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ?");
    else if (courbe=="VITESSE")Query->prepare("SELECT MAX(`VITESSE`) FROM `donnees` WHERE DATE_FORMAT(`DATE`, GET_FORMAT(DATE,('EUR'))) LIKE ?");
    Query->addBindValue(date);
    Query->exec();
    Query->next();
    axeYmax=Query->value(0).toString();
    qDebug()<<axeYmax;
    emit maxAxeY(axeYmax);

}

basededonnees::~basededonnees()
{
    db.close();
    qDebug()<<"vous êtes parti";
}

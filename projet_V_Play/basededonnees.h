#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include <QObject>
#include <QtSql>
//#include <QSqlQuery>
#include<QtSql/QSqlQuery>
//#include "projet.h"


class basededonnees : public QObject
{
    Q_OBJECT

public:
    explicit basededonnees(QObject *parent = 0);
    ~basededonnees();

private:
    QString Username;
    QString Hostname;
    QString Password;
    int port;
    QString DataBaseName;
    QSqlDatabase db;
    QSqlQuery* Query;
    QString Text;
    QStringList list;
    QStringList listCourbe;
    QStringList listaxeY;
    QString axeYmax;
    bool Access;
    float LATTI;
    float LONGI;
    float AX;
    float AY;
    float AZ;
    float DEB;
    float V;
    QString date;
    QString courbe;

signals:
    void messageConnect(QString Text);
    void bdd();
    void historique(bool Access);
    void listDate(QStringList list);
    void listNameColumn(QStringList listCourbe);
    void axeY(QStringList listaxeY);
    void maxAxeY(QString axeYmax);

public slots:
    void checkConnexion(QString UName, QString Pass, QString DataB, QString NPort);
    void sendtoDatabase();
    void getDataToProjet(float LAT, float LONG, float X, float Y, float Z, float Deb, float VIT);
    void dateAffiche();
    void afficheNameColumn();
    void recupValeurCombobox(QString date, QString courbe);


};

#endif // BASEDEDONNEES_H

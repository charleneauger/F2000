#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include <QObject>
#include <QtSql>


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

public slots:
    void checkConnexion();
    //QString setData();

};

#endif // BASEDEDONNEES_H

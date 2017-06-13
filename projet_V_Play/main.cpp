#include <QApplication>
#include <VPApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QQmlEngine>
#include <QtQml>
#include "projet.h"
#include "basededonnees.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    VPApplication vplay;


    vplay.setPreservePlatformFonts(true);

    QQmlApplicationEngine engine;
    vplay.initialize(&engine);
    vplay.setMainQmlFileName(QStringLiteral("qml/Main.qml"));
    engine.load(QUrl(vplay.mainQmlFileName()));

    projet p;
    basededonnees b;
    engine.rootContext()->setContextProperty("projet", &p);
    engine.rootContext()->setContextProperty("database", &b);


    QObject::connect(&p, SIGNAL(sendToDataBase(float,float,float,float,float,float,float)), &b, SLOT(getDataToProjet(float,float,float,float,float,float,float)));
    QObject::connect(&b, SIGNAL(bdd()), &b, SLOT(sendtoDatabase()));

    return app.exec();
}

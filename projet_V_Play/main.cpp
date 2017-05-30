#include <QApplication>
#include <VPApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QQmlEngine>
#include "projet.h"

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
    engine.rootContext()->setContextProperty("projet", &p);

    return app.exec();
}

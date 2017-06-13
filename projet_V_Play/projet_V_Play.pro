# allows to add DEPLOYMENTFOLDERS and links to the V-Play library and QtCreator auto-completion
CONFIG += v-play


qmlFolder.source = qml
DEPLOYMENTFOLDERS += qmlFolder # comment for publishing

assetsFolder.source = assets
DEPLOYMENTFOLDERS += assetsFolder

QT       += core gui sql
QT       += serialport
QT       += widgets
QT       += qml network quick positioning location

# Add more folders to ship with the application here

RESOURCES +=  #    resources.qrc # uncomment for publishing


SOURCES += main.cpp \
    projet.cpp \
    basededonnees.cpp

android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
    OTHER_FILES += android/AndroidManifest.xml
}

ios {
    QMAKE_INFO_PLIST = ios/Project-Info.plist
    OTHER_FILES += $$QMAKE_INFO_PLIST
}

# set application icons for win and macx
win32 {
    RC_FILE += win/app_icon.rc
}
macx {
    ICON = macx/app_icon.icns
}

DISTFILES += \
    qml/connexion.qml \
    qml/basededonneesqml.qml

HEADERS += \
    projet.h \
    basededonnees.h

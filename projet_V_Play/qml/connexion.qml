import VPlayApps 1.0
import QtQuick 2.0
import QtQuick.Controls 1.4
import QtLocation 5.6
import QtPositioning 5.5


Page {
    id:connexion
    title: "Connexion"

    Connections{
        target:projet
        onChargementport:{choix.model = list;}              // connexion entre la comboBox (Qml) et le signal (CPP)
        onEnvoieInfoPortCom:{textPortCom.text = Text;}
        onTextConnexion:{textPortCom.text = Text;}
        onTestData:{textReception.text = Donnees;}
        onGpsLatitude:{map.center.latitude = ValeurLAT;
                       map.center.longitude = ValeurLONG;}
        onTimerOK:{temps.running = true;}
    }

    AppButton {
        id: bDetecter
        x: 104
        y: 20
        width: 240
        height: 20
        text: qsTr("Détecter")
        tooltip: "Cliquer pour détecter les ports de communication disponibles"
        onClicked:{projet.lirePort();}
    }

    ComboBox {
        id: choix
        x: 20
        y: 104
        width: 78
        height: 20
        model: ["..."]
        onCurrentTextChanged:{projet.currentTextChanged(choix.currentText);}
    }

    AppText {
        id: label
        x: 20
        y: 81
        font.pixelSize: 12
        text: qsTr("Choisir Port")
    }

    AppButton {
        id: bConnexion
        x: 104
        y: 170
        width: 110
        height: 20
        text: qsTr("Connexion")
        tooltip: "Cliquer pour vous connecter au port communication"
        onClicked:{textPortCom.text = "";
                   projet.connexion(choix.currentText);}
    }

    AppButton {
        id: bDeconnexion
        x: 236
        y: 170
        width: 108
        height: 20
        text: qsTr("Déconnexion")
        onClicked:{projet.deconnexion(choix.currentText)
                   temps.stop();}
    }

    AppText {
        id: textPortCom
        x: 104
        y: 60
        font.pixelSize:14
        text:qsTr("")
    }

    AppText {
        id: textReception
        x: 356
        y: 60
    }

    Timer {
        id: temps
        interval: 2000; running: false; repeat: true
        onTriggered:{projet.emission();}
    }

    AppMap {
        width: 400
        height: 740
        x: 560
        y: 20
        plugin : Plugin {name : "osm"}
        id: map
        maximumZoomLevel: 20    //Zoom max min
        minimumZoomLevel: 13
        center {                //Coordonnée longitude : latitude :
            latitude : 48.689   //Coordonnées d'Avranches
            longitude : -1.365}
    }



}








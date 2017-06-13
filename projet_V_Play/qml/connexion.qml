import VPlayApps 1.0
import QtQuick 2.0
import QtQuick.Controls 1.4
import QtLocation 5.6
import QtPositioning 5.5
import QtQuick.Controls.Styles 1.4


Page {
    id:connexion
    title: "Visualisation temps réel"

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
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:parent.top
        anchors.topMargin: 30
        width: 100
        height: 20
        text: qsTr("Détecter")
        tooltip: "Cliquer pour détecter les ports de communication disponibles"        
    }

    MouseArea {
        id: mousedetecter
        width: bDetecter.width
        height: bDetecter.height
        x:bDetecter.x
        y:bDetecter.y
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked:{projet.lirePort();}
    }

    ComboBox {
        id: choix
        anchors.verticalCenter:textPortCom.verticalCenter
        anchors.right: textPortCom.left
        anchors.rightMargin: 20
        width: 78
        height: 20
        model: ["..."]
        onCurrentTextChanged:{projet.currentTextChanged(choix.currentText);}
    }

    AppText {
        id: label
        anchors.bottom:choix.top
        anchors.left:choix.left
        anchors.bottomMargin: 10
        font.pixelSize: 12
        text: qsTr("Choisir Port")
    }

    AppButton {
        id: bConnexion
        anchors.top: recttext.bottom
        anchors.left: recttext.left
        anchors.topMargin: 20
        width: 100
        height: 20
        text: qsTr("Connexion")
        tooltip: "Cliquer pour vous connecter au port communication"
    }

    MouseArea {
        id: mouseconnexion
        width: bConnexion.width
        height: bConnexion.height
        x:bConnexion.x
        y:bConnexion.y
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked:{textPortCom.text = "";
                   projet.connexion(choix.currentText);}
    }

    AppButton {
        id: bDeconnexion
        anchors.top: recttext.bottom
        anchors.topMargin: 20
        anchors.right: recttext.right
        width: 100
        height: 20
        text: qsTr("Déconnexion")
    }

    MouseArea {
        id: mousedeconnexion
        width: bDeconnexion.width
        height: bDeconnexion.height
        x:bDeconnexion.x
        y:bDeconnexion.y
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked:{projet.deconnexion(choix.currentText)
                   temps.stop();}
    }

    AppText {
        id: textPortCom
        width: 250
        height: 100
        anchors.horizontalCenter: bDetecter.horizontalCenter
        anchors.top: bDetecter.bottom
        anchors.topMargin: 10
        font.pixelSize:14
        text:qsTr("")
    }

    Rectangle{
        id:recttext
        width: textPortCom.width
        height: 2
        border.width: 2
        border.color: "#0BCBED"
        color: "#0BCBED"
        anchors.horizontalCenter: textPortCom.horizontalCenter
        anchors.top: textPortCom.bottom
    }

    AppText {
        id: textReception
        width: 250
        height: 100
        anchors.top:bDeconnexion.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: textPortCom.horizontalCenter
        font.pixelSize:12
    }

    Rectangle{
        id:rectrecep
        width: textReception.width
        height: 2
        border.width: 2
        border.color: "#0BCBED"
        color: "#0BCBED"
        anchors.horizontalCenter: textReception.horizontalCenter
        anchors.top: textReception.bottom
    }

    Timer {
        id: temps
        interval: 2000; running: false; repeat: true
        onTriggered:{projet.emission();}
    }

    AppMap {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: rectrecep.bottom
        anchors.topMargin: 20
        plugin : Plugin {name : "osm"}
        id: map
        maximumZoomLevel: 20    //Zoom max min
        minimumZoomLevel: 13
        center {                //Coordonnée longitude : latitude :
            latitude : 48.689   //Coordonnées d'Avranches
            longitude : -1.365}
    }



}








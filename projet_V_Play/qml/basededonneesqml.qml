import VPlayApps 1.0
import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtCharts 2.0

Page {
    id:basededonnees
    title: "Historique"
    onPushed: {database.dateAffiche();
               database.afficheNameColumn();}

    Connections{
        target:database
        onListDate: {choixdate.model=list;}
        onListNameColumn: {choixcourbe.model=listCourbe;}
    }

    ComboBox {
        id:choixdate
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:label.bottom
        anchors.topMargin: 10
        model: ["..."]
    }

    AppText {
        id:label
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        text:qsTr("Choisir la date de la course:")
    }

    ComboBox {
        id:choixcourbe
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:labelcourbe.bottom
        anchors.topMargin: 10
        model: ["..."]
        onCurrentTextChanged: {database.recupValeurCombobox(choixdate.currentText, choixcourbe.currentText);}
    }

    AppText {
        id:labelcourbe
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: choixdate.bottom
        anchors.topMargin: 20
        text:qsTr("Choisir la courbe:")
    }

    ChartView {
        id:line
        height: 500
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.left:parent.left
        anchors.leftMargin: 10
        antialiasing: true

        /*ValueAxis {
            id: axisX
            min: 0
            max: 2
            tickCount: 0.4
        }*/
        /*ValueAxis {
            id: axisY
            min: 0
        }*/

        LineSeries {
            id:courbe
            name: ""
            //axisX: axisX
            //axisY: axisY
            XYPoint { x: 0; y: 0 }
        }
    }
}

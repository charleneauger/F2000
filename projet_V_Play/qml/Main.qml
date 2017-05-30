import VPlayApps 1.0
import QtQuick 2.5
import QtQuick.Controls 1.4
import QtLocation 5.6
import QtPositioning 5.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.2
import QtQuick.Window 2.0

App {
    width: 980
    height: 850
    id:app

    NavigationStack {

        Page {
            id:principale
            title: qsTr("")
            visible: true
            Image {
                id:lamo
                source: "../assets/lyceelogo.jpg"
                anchors.centerIn: parent
            }

            AppButton {
                id:connexionbt
                anchors.horizontalCenter: lamo.horizontalCenter
                anchors.top: lamo.bottom
                anchors.topMargin: 20
                text: "Accéder à la connexion"

                onClicked: {
                  principale.navigationStack.push(Qt.resolvedUrl("connexion.qml"));
                }
               }

            AppButton {
                id:basededonnees
                anchors.horizontalCenter: connexionbt.horizontalCenter
                anchors.top: connexionbt.bottom
                anchors.topMargin: 20
                text: "Accéder à l'historique"

                onClicked: {
                  principale.navigationStack.push(Qt.resolvedUrl("basededonneesqml.qml"));
                }
               }
        }

    }
}

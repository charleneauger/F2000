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
    id:app

    NavigationStack {

        Page {
            id:principale
            title: qsTr("")
            visible: true

            Connections{
                target: database
               /* onHistorique:{basededonnees.visible=true;
                    mousehistorique.visible=true;}*/
            }

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
                text: "Visualisation temps réel"
            }

            MouseArea {
                id: mouseconnexionbt
                width: connexionbt.width
                height: connexionbt.height
                anchors.horizontalCenter: lamo.horizontalCenter
                anchors.top: lamo.bottom
                anchors.topMargin: 20
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                  principale.navigationStack.push(Qt.resolvedUrl("connexion.qml"));
                }
            }

            AppButton {
                id:basededonnees
                //visible: false
                anchors.horizontalCenter: connexionbt.horizontalCenter
                anchors.top: connexionbt.bottom
                anchors.topMargin: 20
                text: "Historique"
            }

            MouseArea {
                id: mousehistorique
                //visible: false
                width: basededonnees.width
                height: basededonnees.height
                anchors.horizontalCenter: connexionbt.horizontalCenter
                anchors.top: connexionbt.bottom
                anchors.topMargin: 20
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                  principale.navigationStack.push(Qt.resolvedUrl("basededonneesqml.qml"));
                }
            }

            AppButton{
                id: parametre
                anchors.top: parent.TopRight
                width: 80
                height: 80
                tooltip: "Cliquer pour accéder aux paramètres de connexion"
                style: ButtonStyle{
                    background: Image {
                        source: "../assets/parametre.png"
                    }
                }
            }

            MouseArea {
                id:mouseparametre
                width: parametre.width
                height: parametre.height
                x:parametre.x
                y:parametre.y
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                  principale.navigationStack.push(Qt.resolvedUrl("connexionbdd.qml"));
                }
            }



        }
    }
}

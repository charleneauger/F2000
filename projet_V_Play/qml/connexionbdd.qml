import VPlayApps 1.0
import QtQuick 2.0

 Page {
    id:bdd
    title: "Connexion à la Base de données"

    Connections{
        target: database
        onMessageConnect:{affichconnect.text = Text;}
    }

    Image{
        id:cadre
        source: "../assets/cadre.png"
        anchors.fill: parent
    }

        AppText{
            id:affichconnect
            anchors.horizontalCenter: name.horizontalCenter
            anchors.bottom: name.top
            anchors.bottomMargin: 40
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("")
            font.pixelSize:20
        }

        AppTextField{
            id:name
            anchors.horizontalCenter: password.horizontalCenter
            anchors.bottom: password.top
            anchors.bottomMargin: 10
            showClearButton : true
            placeholderText: qsTr("Username")
            font.pixelSize:14
            maximumLength : 25

        }

        Rectangle{
            width: name.width
            height: 2
            border.width: 2
            border.color: "#0BCBED"
            color: "#0BCBED"
            anchors.horizontalCenter: name.horizontalCenter
            anchors.top: name.bottom
        }

        AppTextField{
            id:password
            anchors.horizontalCenter: databasename.horizontalCenter
            anchors.bottom: databasename.top
            anchors.bottomMargin: 10
            showClearButton : true
            placeholderText: qsTr("Password")
            font.pixelSize:14
            maximumLength : 40
            echoMode: TextInput.Password
        }

        Rectangle{
            width: password.width
            height: 2
            border.width: 2
            border.color: "#0BCBED"
            color: "#0BCBED"
            anchors.horizontalCenter: password.horizontalCenter
            anchors.top: password.bottom
        }

        AppTextField{
            id:databasename
            anchors.centerIn: parent
            showClearButton : true
            placeholderText: qsTr("DataBaseName")
            font.pixelSize:14
            maximumLength : 25
        }

        Rectangle{
            width: databasename.width
            height: 2
            border.width: 2
            border.color: "#0BCBED"
            color: "#0BCBED"
            anchors.horizontalCenter: databasename.horizontalCenter
            anchors.top: databasename.bottom
        }

        AppTextField{
            id:port
            anchors.horizontalCenter: databasename.horizontalCenter
            anchors.top: databasename.bottom
            anchors.topMargin: 10
            showClearButton : true
            placeholderText: qsTr("Port")
            font.pixelSize:14
            maximumLength : 25
        }

        Rectangle{
            id: rectport
            width: port.width
            height: 2
            border.width: 2
            border.color: "#0BCBED"
            color: "#0BCBED"
            anchors.horizontalCenter: port.horizontalCenter
            anchors.top: port.bottom
        }

        AppButton {
            id: bConnect
            anchors.top:port.bottom
            anchors.left: port.left
            anchors.topMargin: 30
            width: 100
            height: 20
            text: qsTr("Connexion")
           /* onClicked: {
                database.checkConnexion(name.text, password.text, databasename.text, port.text);
            }*/
        }

        MouseArea {
            id: mousedetecter
            width: bConnect.width
            height: bConnect.height
            x:bConnect.x
            y:bConnect.y
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
            onClicked:{database.checkConnexion(name.text, password.text, databasename.text, port.text);}
        }
}



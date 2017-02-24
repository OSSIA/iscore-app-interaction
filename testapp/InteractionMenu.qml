import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

page {
    visible: true
    width: 390
    height: 500
    color: "#bababa"

    menuBar: MenuBar {
        Menu {
            //title: qsTr("")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }


}

import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: main
    visible: true
    width: 390
    height: 500
    color: "#ffffff"



    menuBar: MenuBar {
        Menu {

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



    MainForm {

        visible : true
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        clip: false
        button.onClicked: visible = false
        // anchors.fill: parent
    }

   //
   //MainForm.button.onClicked: visible = false

 /*    Search {

   //  visible: false
     anchors.rightMargin: 0
     anchors.bottomMargin: 0
     anchors.leftMargin: 0
     anchors.topMargin: 0
}*/






}
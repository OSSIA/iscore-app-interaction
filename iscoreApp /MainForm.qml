import QtQuick 2.0
import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import QtQuick.Controls.Styles 1.4

Item {
   //visible: true
  // id: l
   width: 390
   height: 500
    property alias button: button

    Loader { id: main
              }


    Button {
        id: button
        x: 0
        y: 379
        width: 390
        height: 60
        style: ButtonStyle {
               background: Rectangle {
                   implicitWidth: 100
                   implicitHeight: 25
                   border.width: control.activeFocus ? 2 : 1
                   //border.color: "#820202"
                   radius: 4
                   gradient: Gradient {
                       GradientStop { position: 0 ; color: control.pressed ? "#04407b" : "#04407b" }
                       GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                   }
               }
           }

        MouseArea {
             anchors.fill: parent
             onClicked: {
               main.source = "Search.qml"; // Load a new page

                // button.z = –1     ;    // Hide button
             }
        }
        text: qsTr("Connect")


}


    Text {
        id: text1
        x: 129
        y: 57
        color: "#820202"
        text: qsTr("I-scoreApp ")
        horizontalAlignment: Text.AlignHCenter
        font.italic: true
        font.bold: true
        font.family: "Courier"
        renderType: Text.NativeRendering
        font.pixelSize: 20
    }

    TextField {
        id: textField
        x: 98
        y: 249
        width: 194
        height: 22
        placeholderText: qsTr("Nickname")
    }


}



















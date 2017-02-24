
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4



Page {

   width: 390
   height: 500
    property alias button: button
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

                   radius: 4

               }
           }

        text: qsTr("Connect")

        onClicked: stackView.push("qrc:/Search.qml")
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



















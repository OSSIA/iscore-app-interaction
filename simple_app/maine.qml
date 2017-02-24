import QtQuick 2.7
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import Qt.labs.settings 1.0
import QtQuick.Controls.Styles 1.4
//import QtQuick.Controls 1.4


   ApplicationWindow {
        id: window
        visible: true
        width: 390
        height: 500
        color: "#ffffff"

        StackView {
            id: stackView
            anchors.fill: parent

            initialItem: Pane {
                id: pane



                Column {
                    x: -5
                    y: 133
                    spacing: 100
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
                    }width: parent.width


                    TextField {
                        id: textField
                        x: 98
                        y: 249
                        width: 194
                        height: 22
                        placeholderText: qsTr("Nickname")
                    }


                    Column {
                        spacing: 20
                        anchors.horizontalCenter: parent.horizontalCenter

                        Button {
                            text: "Premier écran"
                            width: itemWidth
                            onClicked: stackView.push("qrc:/CountDown.qml")
                        }


                    }
                }

            }
        }
    }



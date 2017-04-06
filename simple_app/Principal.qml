

import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import Qt.labs.settings 1.0

ApplicationWindow {
    id: window
    width: 360
    height: 520
    visible: true
    //title: "Qt Quick Controls 2"
    property string login: ""
  //  property bool cpushed: false

    signal connectPushed()



    header: ToolBar {
        Material.foreground: "white"

        RowLayout {
            spacing: 20
            anchors.fill: parent

            /*ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source:


                        stackView.depth > 1 ? "images/back.png" :  "images/drawer.png"
                }
                onClicked: {
                    if (stackView.depth > 1) {
                        stackView.pop()
                        listView.currentIndex = -1
                    } else {
                        drawer.open()
                    }
                }
            }*/

            Label {
                id: titleLabel
                text: listView.currentItem ? listView.currentItem.text : "Iscore App"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    //source: "qrc:/images/menu.png"
                }
                onClicked: optionsMenu.open()

          /*      Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    MenuItem {
                        text: "Settings"
                        onTriggered: settingsPopup.open()
                    }
                    MenuItem {
                        text: "About"
                        onTriggered: aboutDialog.open()
                    }
                }*/
            }
        }
    }

    Drawer {
        id: drawer
        width: Math.min(window.width, window.height) / 3 * 2
        height: window.height
        dragMargin: stackView.depth > 1 ? 0 : undefined

        ListView {
            id: listView
            currentIndex: -1
            anchors.fill: parent

            delegate: ItemDelegate {
                width: parent.width
                text: model.title
                highlighted: ListView.isCurrentItem
                onClicked: {
                    if (listView.currentIndex != index) {
                        listView.currentIndex = index
                        stackView.push(model.source)
                    }
                    drawer.close()
                }
            }

            model: ListModel {
                ListElement { title: "BusyIndicator"; source: "qrc:/CountDown.qml" }
                ListElement { title: "Button"; source: "qrc:/CountDown.qml"  }
                ListElement { title: "Disconnect"; source: "qrc:/CountDown.qml"  }

            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: Pane {
            id: pane
            x: -27
            y: 0

            Column {
                x: -5
                y: 133
                spacing: 100


                TextField {
                    id: textField
                    x: 98
                    y: 249
                    width: 194
                    height: 30
                    placeholderText: qsTr("Nickname")
                    onEditingFinished: login = text
                }


                Column {
                    spacing: 20
                    anchors.horizontalCenter: parent.horizontalCenter

                    Button {
                        x: 98
                        y: 300
                        text: "Connect"
                        //width: itemWidth
                        onClicked:
                        {
                           // cpushed = true;
                            connectPushed();
                            stackView.push("qrc:/InteractionsMenu.qml");
                        }
                    }


                }
            }





        }
    }



}

import QtQuick 2.7
import QtQuick.Controls 1.4

Rectangle {
    
    width: 360
    height: 360
    //property alias listView: listView
    property alias mouseArea: mouseArea
    property alias searchArea: searchArea
    property string passJson: "blankJson"
    property string content: "blank"
    
    MouseArea {
        id: searchArea
        visible: true
        anchors.rightMargin: 0
        anchors.bottomMargin: 312
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent


        MouseArea {
            id: mouseArea
            x: 0
            y: 0
            width: 360
            height: 359

            TextField {
                id: textInput
                anchors.left: parent.left
                anchors.leftMargin: 20
                anchors.top: parent.top
                anchors.topMargin: 20
                width: 181
                height: 20
                font.family: "Arial"
                font.capitalization: Font.MixedCase
                placeholderText: "Search an interaction..."
                onEditingFinished: content = text;

            }

            ListView {
                id: listView
                x: 20
                y: 60
                width: parent.width
                height: parent.height
                highlight: Rectangle { color: "transparent"; border.color: "#0000ff"; border.width: 2; z: 1}
                highlightMoveDuration : 0
                currentIndex: -1
                spacing: 10
                boundsBehavior: Flickable.DragAndOvershootBounds
                contentHeight: 0
                contentWidth: 2048
                orientation: ListView.Horizontal
                /*model: ListModel {
                    ListElement {
                        eindex: 0
                        type: "volume"
                        icon: "volume_cursor2.png"
                        description: "Deplacez le curseur vers la droite pour augmenter le volume, et vers la gauche pour le diminuer"
                    }

                    ListElement {
                        eindex: 1
                        type: "volume"
                        icon: "volume_shakeupdown2.png"
                        description: "Secouez votre dispositif vers le haut pour augmenter le volume, et vers le bas pour le diminuer"
                    }

                    ListElement {
                        eindex: 2
                        type: "start and stop music"
                        icon: "music_button2.png"
                        description: "Appuyez sur le bouton pour lancer ou interrompre la musique"
                    }

                    ListElement {
                        eindex: 3
                        type: "color"
                        icon: "color_shake2.png"
                        description: "Secouez votre dispositif pour modifier la couleur des projecteurs"
                    }
                }*/
                model: ListModel {
                    id: listModel
                    Component.onCompleted: {
                        //var i;
                        //for (i=0;i<)
                        //append({"eindex": 0, "type":"volume", "icon":"volume_cursor2.png", "description":"Deplacez le curseur vers la droite pour augmenter le volume, et vers la gauche pour le diminuer"})
                    }
                }

                delegate: Image {
                    id: img
                    source: icon
                    asynchronous: false

                  MouseArea {
                      id: imgMouseArea
                      x: 0
                      y: 0
                      width: 64
                      height: 64
                      onClicked: {
                                  explan.text = description
                                  listView.currentIndex = eindex
                              }
                  }
                }

            }

            Text {
                anchors.bottom: parent.bottom
                id: explan
                text: qsTr("No interaction selected")
            }




        }
    }
}






















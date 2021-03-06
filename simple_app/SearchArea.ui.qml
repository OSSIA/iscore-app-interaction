import QtQuick 2.5

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
        
        TextInput {
            id: textInput
            x: 20
            y: 14
            width: 321
            height: 20
            text: qsTr("Search an interaction...")
            selectionColor: "#ffffff"
            font.family: "Arial"
            font.capitalization: Font.MixedCase
            renderType: Text.NativeRendering
        }
        
        ListView {
            id: listView
            x: 20
            y: 60
            width: 278
            height: 70
            highlightRangeMode: ListView.NoHighlightRange
            spacing: 10
            boundsBehavior: Flickable.DragAndOvershootBounds
            contentHeight: 0
            contentWidth: 2048
            orientation: ListView.Horizontal
            model: ListModel {
                ListElement {
                    icon: "volume_cursor2.png"
                    description: "Deplacez le curseur vers la droite pour augmenter le volume, et vers la gauche pour le diminuer"
                }
                
                ListElement {
                    icon: "volume_shakeupdown2.png"
                    description: "Secouez votre dispositif vers le haut pour augmenter le volume, et vers le bas pour le diminuer"
                }
                
                ListElement {
                    icon: "music_button2.png"
                    description: "Appuyez sur le bouton pour lancer ou interrompre la musique"
                }
                
                ListElement {
                    icon: "color_shake2.png"
                    description: "Secouez votre dispositif pour modifier la couleur des projecteurs"
                }
            }
            /*delegate: Item {
                    x: 5
                    width: 80
                    height: 40
                    Row {
                        id: row1
                        spacing: 10
                        Image {
                              id: img
                              source: icon
                              fillMode: Image.PreserveAspectFit
                              asynchronous: false
                            }
                    }
                }*/
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
                    onClicked: explan.text = description
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

import QtQuick 2.5

Rectangle {
    
    width: 360
    height: 360
    property alias searchArea: searchArea
    property alias mouseArea: mouseArea
    
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
                x: 18
                y: 15
                width: 321
                height: 20
                text: qsTr("Search an interaction")
                font.pixelSize: 12
            }
        }
    }

    GridView {
        id: gridView
        x: 19
        y: 65
        width: 322
        height: 280
        flickableDirection: Flickable.HorizontalAndVerticalFlick
        highlightRangeMode: GridView.NoHighlightRange
        flow: GridView.FlowLeftToRight
        cellWidth: 65
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
            
            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: 5
            height: 50
            Column {
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    x: 5
                    text: name
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.bold: true
                }
                spacing: 5
            }
        }
        cellHeight: 70
    }
}






















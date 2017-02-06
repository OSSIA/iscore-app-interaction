import QtQuick 2.5

GridView {
    id: gridView
    width: 322
    height: 280
    flickableDirection: Flickable.HorizontalAndVerticalFlick
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
        width: 322
        height: 100
        transformOrigin: Item.Center
        Column {
            spacing: 5
        }
        
        Image {
            x: 8
            y: 8
            width: 100
            height: 100
            source: "../../Téléchargements/volume_cursor.png"
        }
    }
    cellHeight: 70
}

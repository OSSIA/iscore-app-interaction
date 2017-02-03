import QtQuick 2.6
import QtQuick.Controls 2.0

Page {
    id: page

    Column {
        spacing: 40
        width: parent.width

        Label {
            width: parent.width
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "Connection loading"
        }

        BusyIndicator {
            readonly property int size: Math.min(page.availableWidth, page.availableHeight) / 5
            width: size
            height: size
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}

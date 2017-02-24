import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import Qt.labs.settings 1.0



Item{
       width: 100
       height: 100
Popup {
    id: connectionError
    x: (page.width - width) / 2
    y: page.height / 6
    width: Math.min(page.width, page.height) / 3 * 2
    height: 250
    modal: true
    focus: true

    contentItem: ColumnLayout {
        id: settingssColumn
        spacing: 20

        Label {
            text: "label"
            font.bold: true
        }

        RowLayout {
            spacing: 5

            Label {
                text: "No connection"
            }

        }
        RowLayout {
            spacing: 5
        BusyIndicator {
            readonly property int size: Math.min(page.availableWidth, page.availableHeight) / 5
            width: size
            height: size
            anchors.horizontalCenter: parent.horizontalCenter
        }

          }
        RowLayout {
            spacing: 5

            Button {
                id: okzButton
                text: "Skip"
                onClicked: {
                    //settings.style = styleBox.displayText
                    connectionError.close()
                }

                Material.foreground: Material.primary
                Material.background: "transparent"
                Material.elevation: 0

                Layout.preferredWidth: 0
                Layout.fillWidth: true
            }

            Button {
                id: cancelButton
                text: "Retry"
                onClicked: {

                    connectionError.close()
                }

                Material.background: "transparent"
                Material.elevation: 0

                Layout.preferredWidth: 0
                Layout.fillWidth: true
            }
        }
    }
}
}

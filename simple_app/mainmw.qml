import QtQuick 2.7
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import Qt.labs.settings 1.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4


import QtQuick 2.6





ApplicationWindow {
    id: window
    visible: true
    width: 390
    height: 500
    color: "#ffffff"

    property int  countdown: 3




    Timer {
        id: countdownTimer
        interval: 1000
        running: window.countdown > 0
        repeat: true
        onTriggered:
        { window.countdown--
          if (window.countdown == 0)
                  stackView.push("qrc:/CountDown.qml")



       }
    }

    StackView {
   id: stackView

    anchors.fill: parent

   initialItem: Pane {
        id: pane
        x: 0
        y: 0


        Text {
            x: 71
            y: 24

                text: "Interaction will start in: "+ window.countdown +" Seconds"

            }



        Text {
            x: 121
            y: 93
            text: "Interaction Name"

        }


        Image {
            id: logo
           width: pane.availableWidth / 2
           height: pane.availableHeight / 2
           anchors.verticalCenterOffset: 27
           anchors.horizontalCenterOffset: -9
           anchors.centerIn: parent
           anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            fillMode: Image.PreserveAspectFit
            source: "qrc:/volume_cursor.png"
        }

        Label {
            x: 105
            text: "Interaction Description"
            anchors.topMargin: 58
            anchors.margins: 20

            anchors.top: logo.bottom
}
}
  }
}









import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    /*MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }*/
    
    InteractionsMenu {
        color: "#aaaa7f"
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background'))
        }


    }

    /*CountDown {
        anchors.fill: parent
    }*/
}

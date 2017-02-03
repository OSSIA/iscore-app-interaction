import QtQuick 2.5

Rectangle {
    property alias mouseArea: mouseArea
    property alias textEdit: textEdit

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
    }

    TextEdit {
        id: textEdit
        color: "#eceaea"
        text: qsTr("Hello world!")
        font.family: "Tahoma"
        selectionColor: "#f10505"
        anchors.horizontalCenterOffset: 14
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 164
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "#ff0000"
            anchors.rightMargin: -114
            anchors.bottomMargin: -164
            anchors.leftMargin: -140
            anchors.topMargin: -147
            border.width: 1
        }
    }
}






















import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import Qt.labs.settings 1.0

Rectangle {
    
    width: 360
    height: 360
    property alias mouseArea: mouseArea
    property alias searchArea: searchArea
    property string feasible: ""
    Component.onCompleted: {
        console.log("Hello "+login);
        function myParserInit()
        {
           if (initReq.readyState == 4)
           {
               var doc = eval('(' + initReq.responseText + ')');
               var i;
               for (i=0;i<doc.interactions.length;i++)
                   feasible = feasible + 't';
           }
        }
        var initReq = new XMLHttpRequest();
        initReq.open("GET", "interactions.json", true);
        initReq.onreadystatechange = myParserInit;
        initReq.send(null);
    }
    
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
                height: 30
                font.family: "Arial"
                font.capitalization: Font.MixedCase
                placeholderText: "Search an interaction..."
                onEditingFinished: {
                    listModel.completeHandler(text);
                    explan.text = "No interaction selected";
                    listView.currentIndex = -1;
                }

            }

            ListView {
                id: listView
                x: 14
                y: 64
                width: 329
                height: 249
                cacheBuffer: 318
                highlight: Rectangle { color: "transparent"; border.color: "#0000ff"; border.width: 2}
                highlightMoveDuration : 0
                currentIndex: -1
                spacing: 10
                boundsBehavior: Flickable.DragAndOvershootBounds
                contentHeight: 0
                contentWidth: 2048
                orientation: ListView.Horizontal

                model: ListModel {
                    id: listModel
                    function completeHandler(string)
                    {
                        function myParserSearch()
                        {
                            if (searchReq.readyState == 4)
                            {
                                var doc = eval('(' + searchReq.responseText + ')');
                                var i;
                                var counter = 0;
                                for (i=0;i<doc.interactions.length;i++)
                                {
                                    var complete = doc.interactions[i].type;
                                    if(feasible[i] == 't' && complete.indexOf(string) != -1)
                                    {
                                        listModel.append({"eindex": counter, "type":complete, "icon":doc.interactions[i].icon,
                                               "description":doc.interactions[i].description});
                                        counter++;
                                    }
                                }
                            }

                        }
                        listModel.clear();
                        var searchReq = new XMLHttpRequest();
                        searchReq.open("GET", "interactions.json", true);
                        searchReq.onreadystatechange = myParserSearch;
                        searchReq.send(null);
                    }
                    Component.onCompleted: {
                        completeHandler("");
                    }

                }

                delegate: Image {
                    id: img
                    source: icon
                    asynchronous: false
                    z: -1

                  MouseArea {
                      id: imgMouseArea
                      x: 0
                      y: 0
                      width: 64
                      height: 64
                      onClicked: {
                                  explan.text = description
                                  listView.currentIndex = eindex
                          console.log("current index: "+listView.currentIndex);
                      }
                  }
                }

                Button {
                    id: button
                    x: 122
                    y: 301
                    text: qsTr("Quit")
                    onClicked: close()
                }

            }

            Text {
                anchors.bottom: parent.bottom
                id: explan
                x: 8
                y: 331
                width: 344
                height: 20
                text: qsTr("No interaction selected")
                fontSizeMode: Text.FixedSize
                anchors.bottomMargin: 8
                maximumLineCount: 2
                wrapMode: Text.WordWrap
            }




        }
    }

    /*Button {
        id: button1
        x: 8
        y: 416
        width: 344
        height: 40
        text: qsTr("Simulate an interaction (DEBUG ONLY)")
        onClicked: stackView.push("qrc:/mainmw.qml")
    }*/


}






















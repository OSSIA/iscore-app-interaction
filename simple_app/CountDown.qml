import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import Qt.labs.settings 1.0


Page{
    id: page
    visible: true
    width: 390
    height: 500
    property int lost: 1
    property int  interactionTime: 15
    property real slidVal : 0

    Text {
        x: 83
        y: 25

            text: "Remaining time for interaction:"+ page.interactionTime

        }



    Text {
        x: 137
        y: 88
        text: "Interaction Name"

    }


        Rectangle {
            id: main
            x: 20
            y: 152
            width: 360
            height: 234

            Timer {
                id: counter
                interval: 1000
                running: page.interactionTime > 0
                repeat: true
                onTriggered:{
                    page.interactionTime--
                    if (page.interactionTime == 0)
                        window.close()
                   /* if (page.interactionTime == 3)
                        connectionError.open()
                    if (page.interactionTime == 1)
                        connectionError.close()
                       */
                }

            }
        }

        Slider {
            anchors.centerIn: parent
            style: SliderStyle {
                groove: Rectangle {
                    implicitWidth: 200
                    implicitHeight: 8
                    color: "gray"
                    radius: 8
                }
                handle: Rectangle {
                    anchors.centerIn: parent
                    color: control.pressed ? "white" : "lightgray"
                    border.color: "gray"
                    border.width: 2
                    implicitWidth: 34
                    implicitHeight: 34
                    radius: 12
                }
            }
            onValueChanged: {
                slidVal = value
                changeSlide(slidVal)
                //console.log("valeur " + slidVal)
            }
        }




    Button {
        x: 137
        y: 416
        text: "Finish Interaction"
           onClicked: {
               // connectionError.open();
                window.close()
              }

    }

  //         }
/*
       Popup {
           id: done
           x: (page.width - width) / 2
           y: page.height / 6
           width: Math.min(page.width, page.height) / 3 * 2
           height: 200
           modal: true
           focus: true

           contentItem: ColumnLayout {
               id: settingsColumn
               spacing: 20

               Label {
                   text: "label"
                   font.bold: true
               }

               RowLayout {
                   spacing: 10

                   Label {
                       text: "Interaction Completed"
                   }
                }
           }
           closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
       }
*/


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


























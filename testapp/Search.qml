import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
page {
Item {
    width: 390
    height: 500

    Rectangle {
        id: rectangle
        x: 95
        y: 118
        width: 200
        height: 200
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#ffffff"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
        }
    }
}
}

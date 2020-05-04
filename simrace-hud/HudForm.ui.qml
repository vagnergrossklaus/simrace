import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Extras 1.4

Item {
    id: element
    width: 600
    height: 800
    property alias gauge1: gauge1
    property alias gauge: gauge

    property var vehicle: undefined

    Gauge {
        id: gauge
        x: 64
        width: 68
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        tickmarkStepSize: 20
        maximumValue: 300
        value: vehicle.speed
    }

    TextEdit {
        id: textEdit
        x: 377
        y: 51
        width: 155
        height: 179
        text: vehicle.transmission.gear
        font.pixelSize: 64
    }

    Gauge {
        id: gauge1
        x: 215
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        tickmarkStepSize: 1000
        minorTickmarkCount: 1
        value: vehicle.engine.rpm
        maximumValue: vehicle.engine.maxRpm
    }
}

/*##^##
Designer {
    D{i:1;anchors_height:392;anchors_y:0}D{i:3;anchors_y:79}
}
##^##*/


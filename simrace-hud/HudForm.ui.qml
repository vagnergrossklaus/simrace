import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: element
    width: 480
    height: 320
    property alias ggeRpm: ggeRpm

    property var vehicle: undefined

    Rectangle {
        id: backgroud
        anchors.fill: parent
        color: "#000000"
    }

    Gauge {
        id: ggeRpm
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        tickmarkStepSize: 1
        minorTickmarkCount: 1
        value: vehicle.engine.rpm / 1000
        maximumValue: vehicle.engine.maxRpm / 1000
        orientation: Qt.Horizontal
    }

    DigitalGauge {
        id: rpm
        height: 70
        anchors.top: ggeRpm.bottom
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: gear.left
        anchors.rightMargin: 8

        txtLabel.text: "RPM"
        txtData.text: vehicle.engine.rpm
        txtData.font.pixelSize: 64
        txtData.horizontalAlignment: Qt.AlignRight
    }

    DigitalGauge {
        id: speed
        width: 100
        height: 70
        anchors.top: rpm.bottom
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: gear.left
        anchors.rightMargin: 8
        color: "#0000FF"

        txtLabel.text: "Speed"
        txtData.text: vehicle.speed
        txtData.font.pixelSize: 64
        txtData.horizontalAlignment: Qt.AlignRight
    }

    DigitalGauge {
        id: gear
        width: 100
        height: 148
        anchors.top: ggeRpm.bottom
        anchors.topMargin: 8
        anchors.horizontalCenter: parent.horizontalCenter

        txtLabel.text: "Gear"
        txtData.text: vehicle.transmission.gear
    }

    DigitalGauge {
        id: lapTime
        height: 40
        anchors.top: ggeRpm.bottom
        anchors.topMargin: 8
        anchors.left: gear.right
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8

        txtLabel.text: "Lap Time"
        txtData.text: "00:00.000"
        txtData.font.pixelSize: 16
    }

    DigitalGauge {
        id: fuel
        height: 40
        width: 75
        anchors.top: lapTime.bottom
        anchors.topMargin: 8
        anchors.left: gear.right
        anchors.leftMargin: 8
        anchors.right: oil.left
        anchors.rightMargin: 8

        txtLabel.text: "Fuel"
        txtData.text: vehicle.fuel
        txtData.font.pixelSize: 16
    }

    DigitalGauge {
        id: oil
        height: 40
        width: 75
        anchors.top: lapTime.bottom
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8

        txtLabel.text: "Oil Pressure"
        txtData.text: vehicle.engine.oilPressure
        txtData.font.pixelSize: 16
    }
}

/*##^##
Designer {
    D{i:2;anchors_x:8;anchors_y:8}
}
##^##*/


import QtQuick 2.4

Rectangle {

    property alias txtLabel: txtLabel
    property alias txtData: txtData

    width: 100
    height: 140
    color: "#000000"
    border.width: 2
    border.color: "#FFFFFF"

    Text {
        id: txtLabel
        anchors.top: parent.top
        anchors.topMargin: 2
        anchors.left: parent.left
        anchors.leftMargin: 2
        text: label
        color: "#FFFFFF"
        horizontalAlignment: Qt.AlignHCenter
        font.pixelSize: 12
    }

    Text {
        id: txtData
        anchors.fill: parent
        text: data
        color: "#FFFFFF"
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        font.pixelSize: 128
    }
}

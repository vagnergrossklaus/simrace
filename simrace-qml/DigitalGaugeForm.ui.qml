import QtQuick 2.4

Rectangle {

    property alias name: value

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
        text: "Label"
        color: "#FFFFFF"
        horizontalAlignment: Qt.AlignHCenter
        font.pixelSize: 12
    }

    Text {
        id: txtData
        anchors.fill: parent
        text: "-"
        color: "#FFFFFF"
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        font.pixelSize: 128
    }
}

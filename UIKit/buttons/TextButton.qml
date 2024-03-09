import QtQuick 2.15

Rectangle {
    property string text: qsTr("Button")

    signal clicked

    implicitWidth: _text.width
    implicitHeight: _text.height

    color: _mouseArea.pressed ? Qt.darker("gray", 1.2) : "gray"
    radius: 3

    Text {
        id: _text
        leftPadding: 12
        rightPadding: 12
        topPadding: 6
        bottomPadding: 6
        text: parent.text
    }

    MouseArea {
        id: _mouseArea
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
        onClicked: {
            parent.clicked()
        }
    }
}

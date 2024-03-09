import QtQuick 2.15
import QtQuick.Window 2.15
import UIKit 1.0
import UIKit.Buttons 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("qt5_cmake_qml_plugin_example")

    UIKitTheme {}

    TextButton {
        anchors.centerIn: parent
    }
}

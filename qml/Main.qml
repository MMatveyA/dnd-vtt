import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: main

    height: 480
    title: qsTr("DnD - VTT")
    visible: true
    width: 640

    StackView {
        id: stackView

        anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter
        initialItem: screenManager.getScreenQml("Home")
    }
}

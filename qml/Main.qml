import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: main
    width: 640
    height: 480
    visible: true
    title: qsTr("DnD - VTT")

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: screenManager.getScreenQml("Home")
    }
}

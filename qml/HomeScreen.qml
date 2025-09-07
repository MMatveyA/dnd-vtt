import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    Column {
        anchors.centerIn: parent
        spacing: 20

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Игра"

            onClicked: stackView.push(screenManager.getScreenQml("Game"))
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Мои карты"

            onClicked: stackView.push(screenManager.getScreenQml("Maps"))
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Справка"

            onClicked: stackView.push(screenManager.getScreenQml("Help"))
        }
    }
}

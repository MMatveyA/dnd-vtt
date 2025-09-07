import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    Column {
        anchors.centerIn: parent
        spacing: 20

        Button {
            text: "Мои карты"

            onClicked: stackView.push(screenManager.getScreenQml("Maps"))
        }

        Button {
            text: "Справка"

            onClicked: stackView.push(screenManager.getScreenQml("Help"))
        }
    }
}

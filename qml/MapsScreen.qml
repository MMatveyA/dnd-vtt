import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Здесь будут ваши карты"
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Назад"

            onClicked: stackView.pop()
        }
    }
}

import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: "Справка"
        }

        Button {
            text: "Назад"

            onClicked: stackView.pop()
        }
    }
}

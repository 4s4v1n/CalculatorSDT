import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "components"
import "pages"

ApplicationWindow {
    id: window
    width: 600
    height: 800
    flags: Qt.Window
    visible: true

    minimumWidth: 600
    maximumWidth: 600
    minimumHeight: 800
    maximumHeight: 800

    TabBar {
        id: bar
        width: parent.width

        TabButton {
            text: qsTr("Конвертер")
        }

        TabButton {
            text: qsTr("История")
        }

        TabButton {
            text: qsTr("Справка")
        }
    }

    StackLayout {
        anchors {
            top: bar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        currentIndex: bar.currentIndex
        focus: true

        MainPage {}
        HistoryPage {}
        ReferencePage {}
    }
}

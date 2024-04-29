import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: root

    ColumnLayout {
            anchors.fill: parent
            spacing: 0

            HorizontalHeaderView {
                id: horizontalHeader

                reuseItems: false
                syncView: tableView
                height: 30
                Layout.fillWidth: true
                boundsBehavior:Flickable.StopAtBounds

                delegate: Rectangle {
                    id: columnHeader
                    color: "#eee"
                    border.color: "#bbb"
                    border.width: 1
                    implicitWidth: root.width / 4
                    implicitHeight: 30

                    Text {
                        id: headerText
                        anchors.centerIn: parent
                        text: display
                    }

                }
            }

            TableView {
                id: tableView
                clip: true
                boundsBehavior: Flickable.StopAtBounds
                model: HistoryModel

                Layout.fillWidth: true
                Layout.fillHeight: true

                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AsNeeded
                    active: true
                    onActiveChanged: {
                        if (!active)
                            active = true;
                    }
                }

                ScrollBar.horizontal: ScrollBar {
                    policy: ScrollBar.AsNeeded
                    active: true
                    onActiveChanged: {
                        if (!active)
                            active = true;
                    }
                }

                delegate: Rectangle {
                    implicitHeight: 26
                    implicitWidth: 150
                    border.color: "#bbb"
                    border.width: 1

                    Text {
                        id: cellText
                        text: display
                        anchors.verticalCenter: parent.verticalCenter
                        x: 4
                    }
                }
            }
        }
}

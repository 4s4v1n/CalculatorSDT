import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    property alias inputValue: number_line.text
    property alias inputBase: spinbox.value

    signal outputBaseValueChanged()

    component BaseText : Text {
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignHCenter

        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: parent.width / parent.columns
        Layout.preferredHeight: parent.height / parent.rows
    }

    Rectangle {
        anchors.fill: parent

        BaseText {
            id: number_line
            height: 50

            anchors {
                left: parent.left
                right: parent.right
                top: parent.top
                margins: 30
            }
        }

        BaseText {
            id: base_label
            text: qsTr("Основание")
            height: 30

            anchors {
                left: parent.left
                top: number_line.bottom
                margins: 30
            }
        }

        SpinBox {
            id: spinbox
            from: 2
            to: 16
            value: 2
            height: 30

            anchors {
                left: parent.left
                top: base_label.bottom
                margins: 30
            }

            onValueChanged: {
                slider.value = value
                Controller.setBase(spinbox.value)
            }

            Component.onCompleted: {
                Controller.setBase(spinbox.value)
            }
        }

        Slider {
            id: slider
            from: 2
            to: 16
            stepSize: 1
            snapMode: Slider.SnapAlways
            width: 200

            anchors {
                top: base_label.bottom
                right: parent.right
                margins: 30
            }

            onValueChanged: {
                spinbox.value = value
            }
        }
    }
}

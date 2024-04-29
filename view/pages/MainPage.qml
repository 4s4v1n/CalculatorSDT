import QtQuick

import "../components"
import "../conversion.js" as Conversion

Item {
    id: root
    focus: true

    TopPanel {
        id: top_panel
        height: parent.height / 2

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }

        // onOutputBaseValueChanged: {
        //     top_panel.outputValue = Controller.convert()
        // }
    }

    BottomPanel {
        id: bottom_panel
        height: parent.height / 2
        inputValue: top_panel.inputValue
        inputBase: top_panel.inputBase

        anchors {
            top: top_panel.bottom
            left: parent.left
            right: parent.right
        }

        onTextButtonClicked: (text) => {
            top_panel.inputValue += text

            Controller.addExpression(text)
        }

        onClearAllButtonClicked: () => {
            top_panel.inputValue  = ""

            Controller.clearAll()
        }

        onClearEntryButtonClicked: () => {
            top_panel.inputValue = top_panel.inputValue.slice(0, -1)
            Controller.clearEntry()
        }

        onCalculateButtonClicked: () => {
            top_panel.inputValue = Controller.calculate()
        }
    }

    Keys.onPressed: (event) => {
        var key   = event.key
        var text  = event.text
        var base  = top_panel.inputBase
        var value = top_panel.inputValue

        if ((key >= Qt.Key_0 && key <= Qt.Key_9 || key >= Qt.Key_A && key <= Qt.Key_F)) {
            if (value === "0") {
                return
            }
            if (Conversion.hexCharacterToDecimal(text) >= base) {
                return
            }
            top_panel.inputValue += text

            Controller.addSymbol(text)
        } else if (key === Qt.Key_Period && value !== "" && value.indexOf(".") === -1) {
            top_panel.inputValue += text

            Controller.addSymbol(text)
        } else if (key === Qt.Key_Minus && value === "") {
            top_panel.inputValue += text

            Controller.addSymbol(text)
        }
    }

    Keys.onEnterPressed: (event) => {
        if (top_panel.inputValue !== "") {
            // top_panel.outputValue = Controller.convert()
        }
    }

    Keys.onBackPressed: (event) => {
        if (top_panel.inputValue !== "") {
            top_panel.inputValue = top_panel.inputValue.slice(0, -1)
            Controller.clearEntry()
        }
    }

    Keys.onEscapePressed: (event) => {
        top_panel.inputValue  = ""
        // top_panel.outputValue = ""

        Controller.clearAll()
    }

    Keys.onReleased: (event) => {
        root.focus = true
    }
}

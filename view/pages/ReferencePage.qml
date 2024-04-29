import QtQuick

Item {
    Text {
        anchors {
            fill: parent
            centerIn: parent
            margins: 30
        }
        verticalAlignment: Text.AlignHCenter

        text: "Конвертер чисел из n-ричной в m-ричную систем счисления (2 <= n и m <= 16)\n\n" +
              "Имеется:\n" +
              "1. Конвертер\n" +
              "2. История конвертаций за одну сессию\n" +
              "3. Справка\n\n" +
              "Работу выполнили: Бодров, Савин, Тарыма"
    }
}

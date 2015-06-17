import QtQuick 2.0

Item {
    width: 600
    height: 600

    Column {
        id: column1
        width: 200
        height: 400

        Row {
            id: row1
            width: 188
            height: 78

            Text {
                id: text1
                text: qsTr("param1")
                font.pixelSize: 12
            }

            TextInput {
                id: textInput1
                width: 80
                height: 20
                text: qsTr("parameter1 value")
                font.pixelSize: 12
            }

        }

        Row {
            id: row2
            width: 200
            height: 400
        }
    }
}


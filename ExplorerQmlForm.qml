import QtQuick 2.0
import QtQuick.Controls 1.2
import com.whichwaytoday.httprequest 1.0
Item {
    width: 600
    height: 600

    HttpRequest {
        id: myrequest
        onFinished: processRequest(data);
    }

    function fetchUrl(){
        console.log("processData");
        myrequest.setUrlString("http://localhost:9080");
        myrequest.fetch();
    }

    function processRequest(data)
    {
        result.text = data;
    }

    Column {
        id: column1
        spacing: 5
        anchors.fill: parent

        Row {
            id: row1
            height: 78
            anchors.right: parent.right
            anchors.rightMargin: 412
            anchors.left: parent.left
            anchors.leftMargin: 0
            spacing: 5

            Label {
                id: label1
                text: qsTr("param1")
            }

            TextField {
                id: textField1
                text: "Param1 value"
                placeholderText: qsTr("Text Field")
            }

        }

        Row {
            id: row2
            height: 78
            anchors.right: parent.right
            anchors.rightMargin: 400
            anchors.left: parent.left
            anchors.leftMargin: 0

            Button {
                id: button1
                text: qsTr("Fetch")
                onClicked: fetchUrl();
            }
        }

        Row {
            id: row3
            height: 400
            anchors.right: parent.right
            anchors.rightMargin: 400
            anchors.left: parent.left
            anchors.leftMargin: 0

            TextEdit {
                id: result
                height: 20
                text: qsTr("result data")
                font.pixelSize: 14
            }
        }
    }
}


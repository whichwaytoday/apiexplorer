import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1
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
        myrequest.setUrl("http://localhost:9080");
        myrequest.fetch();
    }

    function processRequest(data)
    {
        result.text = data;
    }

    ColumnLayout {
        id: column1
        spacing: 5
        anchors.fill: parent
        //fillWidth: true


        RowLayout {
            id: row1
            //height: 78
            //anchors.fill: parent
            anchors.margins: 5
            spacing: 5
            //fillWidth: true

            Label {
                id: label1
                text: qsTr("param1")
            }

            TextField {
                id: textField1
                text: "Param1 value"
                placeholderText: qsTr("Text Field")
                Layout.fillWidth: true
            }

        }
        RowLayout {
            id: row2
            //height: 78
            //sanchors.fill: parent
            anchors.margins: 5
            spacing: 5
            //fillWidth: true

            Label {
                id: label2
                text: qsTr("param2")
            }

            TextField {
                id: textField2
                text: "Param2 value"
                placeholderText: qsTr("Text Field")
                Layout.fillWidth: true
            }

        }

        RowLayout {
            id: row3
            //height: 78
            //anchors.fill: parent
            anchors.margins: 5

            Button {
                id: button1
                text: qsTr("Fetch")
                onClicked: fetchUrl();
                Layout.fillWidth: true
            }
        }

        RowLayout {
            id: row4
            height: 400
            //anchors.right: parent.right
            //anchors.left: parent.left
            anchors.margins: 5

                TextArea {
                    id: result
                    //height: 200
                    //width: parent.width
                    text: qsTr("result data")
                    font.pixelSize: 14
                    Layout.fillHeight: true
                    Layout.fillWidth: true

            }
        }
    }
}


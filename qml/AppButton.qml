/*******************************************
**       Mohsen Abdollahzadeh Kondori     **
**       Email: MohsenKondori@yahoo.com   **
********************************************/

import QtQuick 2.0

Rectangle {
    id: button

    property bool checked: false
    property alias text: buttonText.text
    property alias imageSource: visualIcon.source

    Accessible.name: text
    Accessible.description: "This button does " + text
    Accessible.role: Accessible.Button
    Accessible.onPressAction: button.clicked()

    signal clicked

    implicitWidth: 90
    implicitHeight: 25

    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: "grey"
        }
        GradientStop {
            position: 1.0
            color: button.focus ? "red" : "grey"
        }
    }
    radius: 10
    antialiasing: true

    Text {
        id: buttonText
        text: parent.description
        anchors.centerIn: parent
        font.pixelSize: parent.height * .5
        style: Text.Normal
        color: enabled ? "white" : "#CACFD2"
        styleColor: "black"
    }

    Image {
        id: visualIcon
        anchors {
            rightMargin: 5
            leftMargin: 5
            bottomMargin: 5
            topMargin: 5
            bottom: parent.bottom
            top: parent.top
            left: parent.left
            right: buttonText.left
        }
        source: ""
    }
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: parent.clicked()
    }

    Keys.onSpacePressed: clicked()
}

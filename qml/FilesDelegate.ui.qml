/*******************************************
**       Mohsen Abdollahzadeh Kondori     **
**       Email: MohsenKondori@yahoo.com   **
********************************************/
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

ItemDelegate {
    id: delegate

    checkable: true

    contentItem: ColumnLayout {
        spacing: 10

        Label {
            text: fileName
            font.bold: true
            elide: Text.ElideRight
            Layout.fillWidth: true
        }

        GridLayout {
            id: grid
            visible: false

            columns: 2
            rowSpacing: 10
            columnSpacing: 10

            Label {
                text: qsTr("Path:")
                Layout.leftMargin: 60
            }

            Label {
                text: path
                font.bold: true
                elide: Text.ElideRight
                Layout.fillWidth: true
            }

            Label {
                text: qsTr("Size:")
                Layout.leftMargin: 60
            }

            Label {
                text: size
                font.bold: true
                elide: Text.ElideRight
                Layout.fillWidth: true
            }
        }
    }

    states: [
        State {
            name: "expanded"
            when: delegate.checked

            PropertyChanges {
                target: grid
                visible: true
            }
        }
    ]
}

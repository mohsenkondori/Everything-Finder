/*******************************************
**       Mohsen Abdollahzadeh Kondori     **
**       Email: MohsenKondori@yahoo.com   **
********************************************/

import QtQuick 2.12
import QtQuick.Controls 2.12

ToolBar {
    id: background

    Label {
        id: label
        text: section
        anchors.fill: parent
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
    }
}

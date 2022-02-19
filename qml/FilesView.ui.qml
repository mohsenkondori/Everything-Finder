/*******************************************
**       Mohsen Abdollahzadeh Kondori     **
**       Email: MohsenKondori@yahoo.com   **
********************************************/

import QtQuick 2.12
import QtQuick.Controls 2.12
import Backend 1.0

ListView {
    id: listView

    signal pressAndHold(int index)

    width: 320
    height: 480

    focus: true
    boundsBehavior: Flickable.StopAtBounds

    section.property: "fileName"
    section.criteria: ViewSection.FirstCharacter
    section.delegate: SectionDelegate {
        width: listView.width
    }

    delegate: FilesDelegate {
        id: delegate
        width: listView.width
        onPressAndHold: listView.pressAndHold(index)
    }

    model: FilesModel {
        id: filesModel
    }

    ScrollBar.vertical: ScrollBar {}
}

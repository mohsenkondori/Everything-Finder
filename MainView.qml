/*******************************************
**       Mohsen Abdollahzadeh Kondori     **
**       Email: MohsenKondori@yahoo.com   **
********************************************/

import QtQuick 2.0
import QtQuick.Dialogs 1.1
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0

import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.15

import Backend 1.0
import "qml"

ApplicationWindow {
    id: window
    visible: true
    title: "Everything Finder"
    width: 580
    height: 480
    minimumWidth: 500
    minimumHeight: 200

    // ------------------------------      Properties      ----------------------------
    // ********************************************************************************
    property real screenWidth    : 580.0
    property real marginWidth    : 10.0
    property string searchText   : ""
    property int currentFile: -1
    property int timer: 0
    property bool isStop: false
    property bool isRunning: false

    // ------------------------------     signals     ------------------------------
    // ********************************************************************************
    signal setSearchText(var directory, var searchText);
    signal searchFiles();
    signal openSelectedFileirectory(var fileName, var currentFile, var isOpenFile);
    signal setStoptoFinder(var isStop);

    // ------------------------------   Slots        ------------------------------
    // ********************************************************************************
    function updateListView(lists)
    {
        currentFile = -1;
        filesView.model.removeAll();
        for (var i = 0; i < lists.length ; i++) {
            var fileName = (lists[i])["FileName"];
            var path = ((lists[i])["Path"]);
            var size = (lists[i])["Size"] + " bytes";

            filesView.model.append(fileName, path, size);
        }
        isRunning = false;
    }

    function getFinderTime(findertime)
    {
        timer = findertime;
        textCreatorforlFinderInformation();
    }

    function textCreatorforlFinderInformation()
    {
        lFinderInformation.text1 = (filesView.model.rowCount() > 0) ? (qsTr("Found ") + filesView.model.rowCount() + (filesView.model.rowCount() > 1 ? qsTr(" files in ") : qsTr (" file in "))
                                                                 + timer + qsTr("ms")) : qsTr("");
    }


    // filedialog
    FileDialog {
        id: fileDialog
        visible: false
        modality:  Qt.WindowModal
        title:  "Choose a directory"
        selectExisting: false
        selectMultiple: false
        selectFolder: true
        nameFilters: ["All files (*)" ]
        selectedNameFilter: "All files (*)"
        sidebarVisible: true
    }

    Item {
        id: mainItem
        width: 580
        height: 400
        anchors.fill: parent
        anchors.margins: marginWidth
        SystemPalette { id: palette }
        clip: true

        GridLayout {
            id: grid
            property int minimumInputSize: 100
            columnSpacing: 5
            rowSpacing: 5
            rows: 2
            columns: 3
            anchors {
                left: parent.left
                right: parent.right
            }

            AppLabel {
                id: lDirectory
                text: "Directory: "
            }

            AppTextField {
                id: textInputDirectory
                text: fileDialog.folder.toString().replace(/^(file:\/{3})|(qrc:\/{2})|(http:\/{2})/,"")
                Layout.minimumWidth: grid.minimumInputSize
                placeholderText: "Browse or Type a valid path ..."
            }

            AppButton{
                id: btnBrowse
                imageSource: "qrc:/Icons/Browse.png"
                Layout.alignment: Qt.AlignLeft | Qt.AlignCenter
                text: qsTr("Browse")
                onClicked: fileDialog.open()
            }

            AppLabel {
                id: lSearch
                text: "Contain text: "
            }

            AppTextField {
                id: textInputSearch
                Layout.minimumWidth: grid.minimumInputSize
                placeholderText: "Type text for search (Case sensitive) ..."
            }

            AppButton {
                id: btnSearch
                Layout.alignment: Qt.AlignLeft | Qt.AlignBaseline
                text: "Search"
                imageSource: "qrc:/Icons/Search.png" //set icon to buttons.
                enabled: (textInputDirectory.text.length > 0 && !isRunning)
                onClicked: {
                    filesView.model.removeAll();
                    textCreatorforlFinderInformation();
                    isRunning = true
                    isStop = false;
                    setStoptoFinder(isStop);
                    setSearchText(textInputDirectory.text, textInputSearch.text);
                    searchFiles();
                }
            }
        }

        Item {
            id: scrollView
            clip: true
            anchors {
                left: parent.left
                right: parent.right
                top: grid.bottom
                bottom: bottomBar.top
                leftMargin: marginWidth
                rightMargin: marginWidth
            }
            width: mainItem.width
            Layout.fillHeight: true

            ColumnLayout {
                id: columnLayout1
                spacing: 8
                Layout.fillWidth: true
                width: scrollView.width
                Item { Layout.preferredHeight: 4 } // padding
                FilesView {
                    id: filesView
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    onPressAndHold: {
                        currentFile = index
                        currentFileMenu.open()
                    }
                }

                Menu {
                    id: currentFileMenu
                    x: filesView.width / 2 - width / 2
                    y: parent.height / 4
                    modal: true
                    width: 300
                    Label {
                        id: lMenue
                        padding: 5
                        font.bold: true
                        width: text.length > parent.width ? text.length + marginWidth : parent.width + marginWidth
                        anchors {
                            leftMargin: marginWidth
                            rightMargin: marginWidth
                        }

                        horizontalAlignment: Qt.AlignHCenter
                        text: currentFile > -1 ? filesView.model.get(currentFile).fileName : ""
                    }
                    MenuItem {
                        text: qsTr("Open directory")
                        onTriggered:  openSelectedFileirectory(filesView.model.get(currentFile).fileName,
                                                               filesView.model.get(currentFile).path,
                                                               false)
                    }
                    MenuItem {
                        text: qsTr("Open file")
                        onTriggered: openSelectedFileirectory(filesView.model.get(currentFile).fileName,
                                                              filesView.model.get(currentFile).path,
                                                              true)
                    }
                }
            }
        }

        Rectangle {
            id: bottomBar
            anchors {
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }
            height: buttonRow.height * 1.2
            color: Qt.darker(palette.window, 1.1)
            border.color: Qt.darker(palette.window, 1.3)
            Row {
                id: buttonRow
                spacing: 6
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 12
                height: implicitHeight
                width: parent.width
                AppButton {
                    text: "Browse"
                    imageSource: "qrc:/Icons/Browse.png"
                    anchors.verticalCenter: parent.verticalCenter
                    onClicked: fileDialog.open()
                }

                AppButton {
                    text: "Search"
                    imageSource: "qrc:/Icons/Search.png"
                    anchors.verticalCenter: parent.verticalCenter
                    enabled: btnSearch.enabled
                    onClicked: btnSearch.clicked()
                }

                AppButton {
                    text: "Home"
                    imageSource: "qrc:/Icons/Home.png"
                    anchors.verticalCenter: parent.verticalCenter
                    enabled: fileDialog.shortcuts.hasOwnProperty("home")
                    onClicked: fileDialog.folder = fileDialog.shortcuts.home
                }

                AppButton { // Stop Button
                    id: btnStop
                    imageSource: "qrc:/Icons/Stop.png"
                    text: "Stop"
                    anchors.verticalCenter: parent.verticalCenter
                    enabled: !isStop && isRunning
                    onClicked:{
                        isStop = true;
                        setStoptoFinder(isStop)
                        isRunning = false
                    }
                }

                AppLabel { //FinderInformation label
                    id: lFinderInformation
                    property alias text1: lFinderInformation.text

                    font.pixelSize: 10;
                    font.bold: false
                    y: parent.height / 4
                }
            }
        }
    }
}

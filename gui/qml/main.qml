import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

import Indicators.Models 1.0

import "js/handler.js" as Handler

ApplicationWindow {
    title: qsTr("Testing Dynamic QML")
    width: 600
    height: 600
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    App {
        id: app
        onChanged: Handler.showUsers()
    }

    ColumnLayout {
        id: content
        RowLayout {
            height: 60
            TextField {
                id: nameTxt
                width: 500
                placeholderText: qsTr("Enter name")
            }
            Button {
                id: addBtn
                width: 100
                text: qsTr("Ajouter")
                onClicked : Handler.add(nameTxt.text)
            }
        }
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

    Component.onCompleted: Handler.init()
}
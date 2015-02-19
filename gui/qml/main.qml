import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

import Indicators.Models 1.0

import "js/handler.js" as Handler

ApplicationWindow {
    title: qsTr("Fuzzy Logic Indicator Manager")
    width: 900
    height: 600
    visible: true
    App {
        id: app
        onChanged: Handler.render()
    }

    ColumnLayout {
        anchors.fill: parent
        Rectangle {
            id: miniMenu
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: 30
            color: '#999'
            RowLayout {
                spacing: 0
                MiniButton {
                    width: 65
                    border.width: 0
                    normalColor: '#999'
                    hoverColor: '#bbb'
                    text: 'New'
                    area.onClicked: {
                        indicatorForm.nameField = '';
                        indicatorForm.open()
                    }
                }
                MiniButton {
                    width: 65
                    border.width: 0
                    normalColor: '#999'
                    hoverColor: '#bbb'
                    text: 'Open'
                    area.onClicked: {
                        Handler.setAction('load');
                        fileDialog.open();
                    }
                }
                MiniButton {
                    width: 65
                    border.width: 0
                    normalColor: '#999'
                    hoverColor: '#bbb'
                    text: 'Save'
                    area.onClicked: {
                        Handler.setAction('save');
                        fileDialog.open();
                    }
                }
                MiniButton {
                    width: 70
                    border.width: 0
                    normalColor: '#999'
                    hoverColor: '#bbb'
                    text: 'Export'
                    area.onClicked: {
                        exportForm.open()
                    }
                }
                MiniButton {
                    width: 90
                    border.width: 0
                    normalColor: '#999'
                    hoverColor: '#bbb'
                    text: 'Import XML'
                    area.onClicked: {
                        Handler.setAction('import:XML')
                        fileDialog.open()
                    }
                }
            }
        }
        ScrollView {
            anchors.top: miniMenu.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            Rectangle {
                id: content
                width: parent.width
                color: "#dddddd"
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
    IndicatorForm {
    	id: indicatorForm
        onAccepted: {
        	if( Handler.check('indicator') )
        		Handler.createIndicator(nameField);
        	else
            	indicatorForm.open();
        }
    }
    IndexForm {
    	id: indexForm
        onAccepted: {
            if( Handler.check('index') )
            	Handler.submitIndex(parentId, num, nameField, weightField, borneFField, borneUField, valueField);
            else
                indexForm.open();
    	}
    }
    ModuleForm {
        id: moduleForm
        onAccepted: {
            if( Handler.check('module') )
                Handler.submitModule(parentId, num, nameField, weightField);
            else
                moduleForm.open();
        }
        onExportClicked: {
            Handler.setAction('export:module', num);
            fileDialog.open();
        }
        onImportClicked: {
            Handler.setAction('import:module', parentId);
            fileDialog.open();
        }
    }
    ExportForm {
        id: exportForm
        onAccepted: {
            Handler.setAction('export:' + extension);
            fileDialog.open();
        }
    }
    FileDialog {
    	id: fileDialog
    	title: "Please choose where to save"
		onAccepted: {
			Handler.doAction(fileDialog.fileUrl)
		}
    }
    Component.onCompleted: {
        Handler.init()
    }
    onWidthChanged : Handler.render()
    onHeightChanged : Handler.render()
}
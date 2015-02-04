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
            title: "&File"
            MenuItem {
                text: "&New Indicator"
                onTriggered: indicatorForm.open()
            }
            MenuItem {
                text: "&Save Indicator"
                onTriggered: {
                	Handler.setAction('save');
                	fileDialog.open();
                }
            }
            MenuItem {
                text: "L&oad Indicator"
                onTriggered: {
                	Handler.setAction('load');
                	fileDialog.open();
                }
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    App {
        id: app
        onChanged: Handler.render()
    }

    Rectangle {
        id: content
        color: "#cccccc"
        anchors.fill: parent
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
        	if( nameField != '')
        		Handler.createIndicator(nameField);
        	else
        		indicatorForm.open();
        }
    }

    IndexForm {
    	id: indexForm
        onAccepted: {
        	Handler.submitIndex(parentId, num, nameField, weightField, borneFField, borneUField, valueField);
    	}
    }
    
    ModuleForm {
    	id: moduleForm
        onAccepted: {
        	Handler.submitModule(parentId, num, nameField, weightField);
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
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
    App {
        id: app
        onChanged: Handler.render()
    }

    // menuBar: MenuBar {
    //     Menu {
    //         title: "&File"
    //         MenuItem {
    //             text: "&New Indicator"
    //             onTriggered: indicatorForm.open()
    //         }
    //         MenuItem {
    //             text: "&Save Indicator"
    //             onTriggered: {
    //             	Handler.setAction('save');
    //             	fileDialog.open();
    //             }
    //         }
    //         MenuItem {
    //             text: "L&oad Indicator"
    //             onTriggered: {
    //             	Handler.setAction('load');
    //             	fileDialog.open();
    //             }
    //         }
    //         MenuItem {
    //             text: qsTr("E&xit")
    //             onTriggered: Qt.quit();
    //         }
    //     }
    // }

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
            }
        }
        Rectangle {
            id: content
            anchors.top: miniMenu.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            color: "#cccccc"
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
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.3

Dialog {
    property int num: -1
    property int parentId: -1
    property string nameField
    property string nameColor
    property string weightField
    property string weightColor

    signal importClicked
    signal exportClicked

    title: "Add new module"
    standardButtons: StandardButton.Ok | StandardButton.Cancel
    width: moduleFormContent.width + 20

    GridLayout {
    	id: moduleFormContent
        columns: 2
    	Button {
            id: moduleImportBtn
            visible: (num == -1)
            text: "Import from XML"
            Layout.columnSpan: 2
            onClicked: importClicked()
        }
        Button {
            id: moduleExportBtn
            visible: (num != -1)
            text: "Export from XML"
            Layout.columnSpan: 2
            onClicked: exportClicked()
        }
        Text { 
            text: "Name"
        }
        TextField {
            width: 200
            text: nameField
            style: TextFieldStyle {
                textColor: nameColor
                background: Rectangle {
                    border.color: nameColor
                    border.width: 1
                }
            }
            onTextChanged: nameField = text
        }

        Text { 
            text: "Weight" 
        }
        TextField {
            width: 200
            text: weightField
            style: TextFieldStyle {
                textColor: weightColor
                background: Rectangle {
                    border.color: weightColor
                    border.width: 1
                }
            }
            onTextChanged: weightField = text
        }
    }
}
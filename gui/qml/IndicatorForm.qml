import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.3

Dialog {
    property string nameField
    property string nameColor: "black"
    title: "Create a new indicator"
    standardButtons: StandardButton.Ok | StandardButton.Cancel
    width: indicatorFormContent.width + 20

    ColumnLayout {
    	id: indicatorFormContent
    	width: indicatorFormCaption.width + 20
    	Text {
    		id: indicatorFormCaption
    		text: "Please insert the name of the new indicator :"
    	}

        TextField {
    		id: indicatorFormNameTxt
    		anchors.left: parent.left
    		anchors.right: parent.right
            text: nameField
            style: TextFieldStyle {
                textColor: nameColor
                background: Rectangle {
                    border.color: nameColor
                    border.width: 1
                }
            }
            onTextChanged : nameField = text
    	}
    }
}
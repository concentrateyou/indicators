import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Dialog {
    property string nameField
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
            onTextChanged : nameField = text
    	}
    }
}
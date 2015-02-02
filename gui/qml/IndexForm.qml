import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Dialog {
    property int num: -1
    property int parentId: -1
    property string nameField
    property string weightField
    property string borneFField
    property string borneUField
    property string valueField

    title: "Add new index"
    standardButtons: StandardButton.Ok | StandardButton.Cancel
    width: indicatorFormContent.width + 20

    GridLayout {
    	id: indicatorFormContent
        columns: 2
    	
        Text { 
            text: "Name" 
        }
        TextField {
            width: 200
            text: nameField
            onTextChanged: nameField = text
        }

        Text { 
            text: "Weight" 
        }
        TextField {
            width: 200
            text: weightField
            onTextChanged: weightField = text
        }

        Text { 
            text: "Favorable Borne"
        }
        TextField {
            width: 200
            text: borneFField
            onTextChanged: borneFField = text
        }

        Text { 
            text: "Unfavorable Borne"
        }
        TextField {
            width: 200
            text: borneUField
            onTextChanged: borneUField = text
        }

        Text { 
            text: "Value"
        }
        TextField {
            width: 200
            text: valueField
            onTextChanged: valueField = text
        }

    }
}
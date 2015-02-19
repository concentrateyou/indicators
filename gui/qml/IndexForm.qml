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
    property string nameColor: 'black'
    property string weightField
    property string weightColor: 'black'
    property string borneFField
    property string borneFColor: 'black'
    property string borneUField
    property string borneUColor: 'black'
    property string valueField
    property string valueColor: 'black'

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

        Text { 
            text: "Favorable Borne"
        }
        TextField {
            width: 200
            text: borneFField
            style: TextFieldStyle {
                textColor: borneFColor
                background: Rectangle {
                    border.color: borneFColor
                    border.width: 1
                }
            }
            onTextChanged: borneFField = text
        }

        Text { 
            text: "Unfavorable Borne"
        }
        TextField {
            width: 200
            text: borneUField
            style: TextFieldStyle {
                textColor: borneUColor
                background: Rectangle {
                    border.color: borneUColor
                    border.width: 1
                }
            }
            onTextChanged: borneUField = text
        }

        Text { 
            text: "Value"
        }
        TextField {
            width: 200
            text: valueField
            style: TextFieldStyle {
                textColor: valueColor
                background: Rectangle {
                    border.color: valueColor
                    border.width: 1
                }
            }
            onTextChanged: valueField = text
        }

    }
}
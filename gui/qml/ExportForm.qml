import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Dialog {
    property string extension: 'XML'

    title: "Select the file format"
    standardButtons: StandardButton.Ok
    width: exportFormContent.width + 20

    GridLayout {
    	id: exportFormContent
        columns: 2
    	
        Text { 
            text: "Format" 
        }
        ComboBox {
            model: [ "XML", "PNG", "CSV" ]
            onCurrentTextChanged: {
                extension = currentText
            }
        }
    }
}
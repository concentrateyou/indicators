import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

RowLayout {
    property int num
    property string name

    Text {
        text: name + '(' + num + ')'
    }
    Button {
        text: "delete"
        onClicked : app.removeName(num)
    }
}
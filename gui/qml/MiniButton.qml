import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Rectangle {
	id: btn
	property string normalColor: '#1852B7'
	property string hoverColor: '#5C8CE8'
	property alias text: txt.text
	property alias area: area

	color: normalColor
	width: 30
	height: 30
	border.width: 1
	border.color: "#000000"

	MouseArea {
		id: area
		anchors.fill: parent
		hoverEnabled: true
		onEntered: parent.color = hoverColor
		onExited: parent.color = normalColor
	}
	Text {
		id: txt
		anchors.centerIn: parent
		text: 'X'
	}
}
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Rectangle {
	

	color: '#eee'
	width: {
		if(topMenu.width > content.width)
			return topMenu.width
		return content.width
	}
	height: 70
	border.width: 2
	border.color: '#000000'
	anchors.centerIn: parent

	RowLayout {
		id: topMenu
		height: 32
		spacing: -1
		anchors.top: parent.top
		anchors.right: parent.right
		Item { 
			width: 2
		}
		MiniButton {
			text: '+M'
			normalColor: '#15AF17'
			hoverColor: '#60E959'
			area.onClicked : {
				console.log('I am clicked !')
			}
		}
		MiniButton {
			visible: false
			text: '+I'
			normalColor: '#15AF17'
			hoverColor: '#60E959'
		}
		MiniButton {
			text: '-'
			normalColor: '#39A0D1'
			hoverColor: '#69C0D1'
			area.onClicked : {
				console.log('I am clicked !')
			}
		}
		MiniButton {
			id: closeBtn
			text: 'X'
			normalColor: '#E63434'
			hoverColor: '#FF8D8D'
			area.onClicked : {
				console.log('I am clicked !')
			}
		}
		Item { 
			width: 2
		}
	}
	RowLayout {
		id: content
		anchors.top: topMenu.bottom
		anchors.bottom: parent.bottom
		anchors.horizontalCenter: parent.horizontalCenter
		Item { 
			width: 2
		}
		Text {
			anchors.centerIn: parent
			text: 'My Name is very long'
		}
		Item { 
			width: 2
		}
	}
}
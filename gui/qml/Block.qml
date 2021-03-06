import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Rectangle {
	id: block
	property alias name: nameTxt.text
	property alias weight: weightTxt.text
	property alias borneF: borneFTxt.text
	property alias borneU: borneUTxt.text
	property alias value: valueTxt.text
	property alias withClose: closeBtn.visible
	property alias withIndexAdd: indexAddBtn.visible
	property alias withModuleAdd: moduleAddBtn.visible

	property bool withReduce: true
	property bool isReduced: false
	property int num
	property string type

	signal closed
	signal reduced
	signal expand
	signal indexAddClicked
	signal moduleAddClicked
	signal doubleClicked

	color: '#eee'
	width: {
		if(topMenu.width > content.width)
			return topMenu.width
		return content.width
	}
	height: topMenu.height + content.height
	border.width: 2
	border.color: '#000000'

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
			id: moduleAddBtn
			text: '+M'
			normalColor: '#15AF17'
			hoverColor: '#60E959'
			area.onClicked: moduleAddClicked()
		}
		MiniButton {
			id: indexAddBtn
			text: '+I'
			normalColor: '#15AF17'
			hoverColor: '#60E959'
			area.onClicked: indexAddClicked()
		}
		MiniButton {
			id: reduceBtn
			text: '-'
			normalColor: '#39A0D1'
			hoverColor: '#69C0D1'
			area.onClicked: { 
				reduced();
				isReduced = true;
			}
			visible: ( withReduce && !isReduced )
		}
		MiniButton {
			id: expandBtn
			text: '+'
			normalColor: '#39A0D1'
			hoverColor: '#69C0D1'
			area.onClicked: {
				expand();
				isReduced = false;
			}
			visible: ( withReduce && isReduced )
		}
		MiniButton {
			id: closeBtn
			text: 'X'
			normalColor: '#E63434'
			hoverColor: '#FF8D8D'
			area.onClicked: closed()
		}
		Item { 
			width: 2
		}
	}
	RowLayout {
		id: content
		anchors.top: topMenu.bottom
		anchors.horizontalCenter: parent.horizontalCenter
		Item { 
			width: 2
		}
		ColumnLayout {
			Text {
				id: nameTxt
				height: 30
				anchors.horizontalCenter: parent.horizontalCenter
				text: 'Unknown'
			}
			Text {
				id: valueTxt
				height: 30
				anchors.horizontalCenter: parent.horizontalCenter
				text: 'V: '
			}
			Text {
				id: weightTxt
				height: 30
				anchors.horizontalCenter: parent.horizontalCenter
				text: 'W: '
				visible: (type != 'indicator')
			}
			Text {
				id: borneFTxt
				height: 30
				anchors.horizontalCenter: parent.horizontalCenter
				text: 'BF: '
				visible: (type == 'index')
			}
			Text {
				id: borneUTxt
				height: 30
				anchors.horizontalCenter: parent.horizontalCenter
				text: 'BU: '
				visible: (type == 'index')
			}
			Item {
				height: 5
			}
		}
		Item { 
			width: 2
		}

		MouseArea {
			id: area
			anchors.fill: parent
			hoverEnabled: true
			onEntered: { 
				block.color = '#fff';
				block.border.color = '#39A0D1';
			}
			onExited: {
				block.color = '#eee';
				block.border.color = '#000000';
			}
			onDoubleClicked: block.doubleClicked()
		}
	}
}
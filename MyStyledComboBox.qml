import QtQuick
import QtQuick.Controls.Basic

ComboBox {
    id: root

    property color colorContent: "#F9F8FD"
    property color colorDefault: "#2A60FF"
    property color colorDefaultItems: "#2ADDFF"
    property color colorMouseOver: "#2ABBFF"

    font.family: "Arial"

    contentItem: Text {
        color: colorContent
        text: root.displayText
        font.pointSize: 12
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    background: Rectangle {
        color: colorDefault
        radius: 5
    }

    delegate: ItemDelegate {
        width: root.width
        hoverEnabled: true

        background: Rectangle
        {
            color: root.highlightedIndex === index ? colorMouseOver : colorDefaultItems
            radius: 0
        }

        contentItem: Text {
            color: colorContent
            text: model.modelData.text
            font.pointSize: 11
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }
}

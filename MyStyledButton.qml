import QtQuick
import QtQuick.Controls.Basic

Button {
    id: root

    property color btnColorDefault: "#2A60FF"
    property color btnColorMouseOver: "#2ABBFF"
    property color btnColorClicked: "#2ADDFF"
    property color btnColorContent: "#F9F8FD"

    text: qstr("Button")

    contentItem: Text {
        text: root.text
        color: root.btnColorContent
        font.pixelSize: 15
        font.family: "Arial"
        font.weight: Font.Thin
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    // background style of Button
    background: Rectangle {
        implicitWidth: 75
        implicitHeight: 35
        color: root.down ? btnColorClicked :
                                    (root.hovered ? btnColorMouseOver : btnColorDefault)
        radius: 10
    }
}

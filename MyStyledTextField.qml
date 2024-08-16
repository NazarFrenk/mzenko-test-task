import QtQuick
import QtQuick.Controls.Basic

TextField {
    id: root

    font.pixelSize: 15
    font.family: "Arial"

    signal increase()
    signal decrease()

    MouseArea{
        anchors.fill: parent
        propagateComposedEvents: true
        onClicked:{
            root.forceActiveFocus()
        }

        onWheel: function(wheel){
            if(wheel.angleDelta.y > 0)
                root.increase()
            else
                root.decrease()
        }
    }
}

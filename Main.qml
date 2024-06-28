import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: root

    width: 640
    height: 480
    visible: true
    title: qsTr("Resonant Cacl")

    minimumWidth: 400
    minimumHeight: 400

    TabBar {
        id: bar
        width: parent.width

        TabButton {
            text: qsTr("Resistor Mode")
        }
        TabButton {
            text: qsTr("CR Impedance Mode")
        }
        TabButton {
            text: qsTr("LR Impedance Mode")
        }
    }

    StackLayout {
        width: parent.width
        currentIndex: bar.currentIndex
        anchors.fill: parent

        Item {
            id: resistorTab
            Layout.fillWidth: true
            Layout.fillHeight: true

            ColumnLayout {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                spacing: 20

                RadioButton {
                    id: btnParallel
                    text: qsTr("Parallel")
                    checked: true
                }

                RadioButton {
                    id: btnSeries
                    text: qsTr("Series")
                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    TextField {
                        id: input
                        placeholderText: qsTr("100");
                        validator: RegularExpressionValidator{regularExpression: /^[0-9,/]+$/}
                    }

                    Button {
                        id: btnOkResistor
                        text: qsTr("OK")
                    }
                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Button {
                        id: btnRemoveLastResistor
                        text: qsTr("Remove Last")
                    }

                    Button {
                        id: btnClearResistor
                        text: qsTr("Clear")
                    }
                }

                Label {
                    id: lblData
                    text: "Data label"

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                Label {
                    id: lblResult
                    text: "Result label"

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                Button {
                    id: btnResCalc
                    text: qsTr("Calculate")

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }
        }
        Item {
            id: crTab

            ColumnLayout {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                spacing: 20

                Label {
                    id: lblCrResistor
                    text: "Resistor (Ω):"
                }

                TextField {
                    id: inputCrResitor
                    placeholderText: qsTr("100");
                    validator: RegularExpressionValidator{regularExpression: /^[0-9,/]+$/}
                }

                Label {
                    id: lblCrCapasitor
                    text: "Capacitor (F):"
                }

                TextField {
                    id: inputCrCapasitor
                    placeholderText: qsTr("0,000001");
                    validator: RegularExpressionValidator{regularExpression: /\d+(\,\d+)?\s*F$/}
                }

                Label {
                    id: lblCrFrequency
                    text: "Frequency (Hz):"
                }

                TextField {
                    id: inputCrFrequency
                    placeholderText: qsTr("50");
                    validator: RegularExpressionValidator{regularExpression: /\d+(\,\d+)?\s*Hz$/}
                }

                Label {
                    id: lblCrResult
                    text: "Result Impedance: "

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                Button {
                    id: btnCrCalc
                    text: qsTr("Calculate")

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }
        }
        Item {
            id: lrTab

            ColumnLayout {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                spacing: 20

                Label {
                    id: lblIrResistor
                    text: "Resistor (Ω):"
                }

                TextField {
                    id: inputIrResitor
                    placeholderText: qsTr("100");
                    validator: RegularExpressionValidator{regularExpression: /^[0-9,/]+$/}
                }

                Label {
                    id: lblIrInductor
                    text: "Inductor (H):"
                }

                TextField {
                    id: inputIrInductor
                    placeholderText: qsTr("0,1");
                    validator: RegularExpressionValidator{regularExpression: /\d+(\,\d+)?\s*H$/}
                }

                Label {
                    id: lblIrFrequency
                    text: "Frequency (Hz):"
                }

                TextField {
                    id: inputIrFrequency
                    placeholderText: qsTr("50");
                    validator: RegularExpressionValidator{regularExpression: /\d+(\,\d+)?\s*Hz$/}
                }

                Label {
                    id: lblIrResult
                    text: "Result Impedance:"

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                Button {
                    id: btnLrCalc
                    text: qsTr("Calculate")

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }
        }
    }
}

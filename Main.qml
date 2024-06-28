import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: root

    width: 640
    height: 480
    visible: true
    title: qsTr("Resonant Cacl")

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

            ColumnLayout {
                anchors.fill: parent

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

                Label {
                    id: lblData
                    text: "Data label"
                }

                Label {
                    id: lblResult
                    text: "Result label"
                }

                Button {
                    id: btnResCalc
                    text: qsTr("Calculate")
                }
            }
        }
        Item {
            id: crTab

            ColumnLayout {
                anchors.fill: parent

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
                    text: "Result Impedance:"
                }

                Button {
                    id: btnCrCalc
                    text: qsTr("Calculate")
                }
            }
        }
        Item {
            id: lrTab

            ColumnLayout {
                anchors.fill: parent

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
                }

                Button {
                    id: btnLrCalc
                    text: qsTr("Calculate")
                }
            }
        }
    }
}

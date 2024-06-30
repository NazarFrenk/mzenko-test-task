import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
import CircuitComponentSolver

Window {
    id: root

    width: 640
    height: 480
    visible: true
    title: qsTr("Resonant Cacl")

    minimumWidth: 400
    minimumHeight: 450

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
            text: qsTr("IR Impedance Mode")
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
                    font.pixelSize: 15
                    font.family: "Arial"
                    font.bold: btnParallel.checked
                    checked: true
                }

                RadioButton {
                    id: btnSeries
                    font.pixelSize: 15
                    font.family: "Arial"
                    font.bold: btnSeries.checked
                    text: qsTr("Series")
                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    TextField {
                        id: inputResistor
                        placeholderText: qsTr("100")
                        font.pixelSize: 15
                        font.family: "Arial"
                        validator: RegularExpressionValidator{regularExpression: /^[0-9./]+$/}
                    }

                    MyStyledButton {
                        id: btnOkResistor
                        text: qsTr("OK")

                        onClicked: {
                            CircuitComponentSolver.setResistorValue(inputResistor.text)
                            lblData.text = CircuitComponentSolver.dataResistors
                        }
                    }
                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    MyStyledButton {
                        id: btnRemoveLastResistor
                        text: qsTr("Remove Last")

                        onClicked: {
                            CircuitComponentSolver.removeLastResistorValue()
                            lblData.text = CircuitComponentSolver.dataResistors
                        }
                    }

                    MyStyledButton {
                        id: btnClearResistor
                        text: qsTr("Clear")

                        onClicked: {
                            CircuitComponentSolver.clearResistorsData()
                            lblData.text = CircuitComponentSolver.dataResistors
                        }
                    }
                }

                MyStyledLabel {
                    id: lblData
                    text: "Data: no data"

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                MyStyledLabel {
                    id: lblResult
                    text: "Result: no data"

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                MyStyledButton {
                    id: btnResCalc
                    text: qsTr("Calculate")

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    onClicked: {
                        CircuitComponentSolver.calculateResistance(btnParallel.checked)
                        lblResult.text = CircuitComponentSolver.resultResistors;
                    }
                }
            }
        }
        Item {
            id: crTab

            ColumnLayout {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                spacing: 20

                MyStyledLabel {
                    id: lblCrResistor
                    text: "Resistor (Ω):"
                }

                TextField {
                    id: inputCrResitor
                    placeholderText: qsTr("100")
                    font.pixelSize: 15
                    font.family: "Arial"
                    validator: RegularExpressionValidator{regularExpression: /^[0-9./]+$/}
                }

                MyStyledLabel {
                    id: lblCrCapasitor
                    text: "Capacitor (F):"
                }

                TextField {
                    id: inputCrCapasitor
                    placeholderText: qsTr("0.000001")
                    font.pixelSize: 15
                    font.family: "Arial"
                    validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*F$/}
                }

                MyStyledLabel {
                    id: lblCrFrequency
                    text: "Frequency (Hz):"
                }

                TextField {
                    id: inputCrFrequency
                    placeholderText: qsTr("50")
                    font.pixelSize: 15
                    font.family: "Arial"
                    validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*Hz$/}
                }

                MyStyledLabel {
                    id: lblCrResult
                    text: "Result Impedance: no data"

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                MyStyledButton {
                    id: btnCrCalc
                    text: qsTr("Calculate")

                    onClicked: {
                        CircuitComponentSolver.setResistorCr(inputCrResitor.text)
                        CircuitComponentSolver.setCapasitorCr(inputCrCapasitor.text)
                        CircuitComponentSolver.setFrequencyCr(inputCrFrequency.text)
                        CircuitComponentSolver.createCrResult()
                        lblCrResult.text = CircuitComponentSolver.resultCr
                    }

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }
        }
        Item {
            id: irTab

            ColumnLayout {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                spacing: 20

                MyStyledLabel {
                    id: lblIrResistor
                    text: "Resistor (Ω):"
                }

                TextField {
                    id: inputIrResitor
                    placeholderText: qsTr("100")
                    font.pixelSize: 15
                    font.family: "Arial"
                    validator: RegularExpressionValidator{regularExpression: /^[0-9./]+$/}
                }

                MyStyledLabel {
                    id: lblIrInductor
                    text: "Inductor (H):"
                }

                TextField {
                    id: inputIrInductor
                    placeholderText: qsTr("0.1")
                    font.pixelSize: 15
                    font.family: "Arial"
                    validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*H$/}
                }

                MyStyledLabel {
                    id: lblIrFrequency
                    text: "Frequency (Hz):"
                }

                TextField {
                    id: inputIrFrequency
                    placeholderText: qsTr("50")
                    font.pixelSize: 15
                    font.family: "Arial"
                    validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*Hz$/}
                }

                MyStyledLabel {
                    id: lblIrResult
                    text: "Result Impedance: no data"

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                MyStyledButton {
                    id: btnLrCalc
                    text: qsTr("Calculate")

                    onClicked: {
                        CircuitComponentSolver.setResistorIr(inputIrResitor.text)
                        CircuitComponentSolver.setInductorIr(inputIrInductor.text)
                        CircuitComponentSolver.setFrequencyIr(inputIrFrequency.text)
                        CircuitComponentSolver.createIrResult()
                        lblIrResult.text = CircuitComponentSolver.resultIr
                    }

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }
        }
    }
}

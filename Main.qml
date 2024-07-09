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

                MyStyledRadioButton {
                    id: btnParallel
                    text: qsTr("Parallel")
                    font.bold: btnParallel.checked
                    checked: true
                }

                MyStyledRadioButton {
                    id: btnSeries
                    text: qsTr("Series")
                    font.bold: btnSeries.checked
                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    MyStyledTextField {
                        id: inputResistor
                        placeholderText: qsTr("100")
                        //validator: RegularExpressionValidator{regularExpression: /^[0-9./]+$/}

                        onEditingFinished: {
                            CircuitComponentSolver.resistorValue = inputResistor.text
                        }
                    }

                    MyStyledButton {
                        id: btnOkResistor
                        text: qsTr("OK")

                        onClicked: {
                            CircuitComponentSolver.addNewResistor()
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
                        }
                    }

                    MyStyledButton {
                        id: btnClearResistor
                        text: qsTr("Clear")

                        onClicked: {
                            CircuitComponentSolver.clearResistorsData()
                        }
                    }
                }

                MyStyledLabel {
                    id: lblData
                    text: CircuitComponentSolver.dataResistors

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                MyStyledLabel {
                    id: lblResult
                    text: CircuitComponentSolver.resultResistors

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                MyStyledButton {
                    id: btnResCalc
                    text: qsTr("Calculate")

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    onClicked: {
                        CircuitComponentSolver.calculateResistance(btnParallel.checked)
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

                MyStyledTextField {
                    id: inputCrResitor
                    placeholderText: qsTr("100")
                    //validator: RegularExpressionValidator{regularExpression: /^[0-9./]+$/}

                    onEditingFinished: {
                        CircuitComponentSolver.resistorCr = inputCrResitor.text
                    }
                }

                MyStyledLabel {
                    id: lblCrCapasitor
                    text: "Capacitor (F):"
                }

                MyStyledTextField {
                    id: inputCrCapasitor
                    placeholderText: qsTr("0.000001")
                    //validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*F$/}

                    onEditingFinished: {
                        CircuitComponentSolver.capasitorCr = inputCrCapasitor.text
                    }
                }

                MyStyledLabel {
                    id: lblCrFrequency
                    text: "Frequency (Hz):"
                }

                MyStyledTextField {
                    id: inputCrFrequency
                    placeholderText: qsTr("50")
                    //validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*Hz$/}

                    onEditingFinished: {
                        CircuitComponentSolver.frequencyCr = inputCrFrequency.text
                    }
                }

                MyStyledLabel {
                    id: lblCrResult
                    text: CircuitComponentSolver.resultCr

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                MyStyledButton {
                    id: btnCrCalc
                    text: qsTr("Calculate")

                    onClicked: {
                        CircuitComponentSolver.createCrResult()
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

                MyStyledTextField {
                    id: inputIrResitor
                    placeholderText: qsTr("100")
                    //validator: RegularExpressionValidator{regularExpression: /^[0-9./]+$/}

                    onEditingFinished: {
                        CircuitComponentSolver.resistorIr = inputIrResitor.text
                    }
                }

                MyStyledLabel {
                    id: lblIrInductor
                    text: "Inductor (H):"
                }

                MyStyledTextField {
                    id: inputIrInductor
                    placeholderText: qsTr("0.1")
                    //validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*H$/}

                    onEditingFinished: {
                        CircuitComponentSolver.inductorIr = inputIrInductor.text
                    }
                }

                MyStyledLabel {
                    id: lblIrFrequency
                    text: "Frequency (Hz):"
                }

                MyStyledTextField {
                    id: inputIrFrequency
                    placeholderText: qsTr("50")
                    //validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*Hz$

                    onEditingFinished: {
                        CircuitComponentSolver.frequencyIr = inputIrFrequency.text
                    }
                }

                MyStyledLabel {
                    id: lblIrResult
                    text: CircuitComponentSolver.resultIr

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                MyStyledButton {
                    id: btnLrCalc
                    text: qsTr("Calculate")

                    onClicked: {
                        CircuitComponentSolver.createIrResult()
                    }

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }
        }
    }
}

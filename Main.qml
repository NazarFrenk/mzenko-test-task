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
    // change 1

    minimumWidth: 400
    minimumHeight: 450
    // change 2

    property var multiplier_model: [
        {text: qsTr("µ (micro)"), value: 1E-6},
        {text: qsTr("m (milli)"), value: 1E-3},
        {text: qsTr("(no prefix)"), value: 1},
        {text: qsTr("k (kilo)"), value: 1E+3}
    ]

    TabBar {
        id: bar
        width: parent.width
        // target

        TabButton {
            text: qsTr("Resistor Mode")
        }
        TabButton {
            text: qsTr("CR Impedance Mode")
        }
        TabButton {
            text: qsTr("IR Impedance Mode")
        }

        onCurrentIndexChanged: {
            CircuitComponentSolver.currentTapIndex = currentIndex
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
                    checked: CircuitComponentSolver.isParallel

                    onCheckedChanged: {
                        CircuitComponentSolver.isParallel = btnParallel.checked
                    }
                }

                MyStyledRadioButton {
                    id: btnSeries
                    text: qsTr("Series")
                    font.bold: btnSeries.checked

                    onCheckedChanged: {
                        CircuitComponentSolver.isParallel = !btnSeries.checked
                    }
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

                    text: {
                        console.log("inputCrResitor::text", CircuitComponentSolver.resistorCr)
                        return CircuitComponentSolver.resistorCr
                    }

                    onEditingFinished: {
                        CircuitComponentSolver.resistorCr = inputCrResitor.text
                    }

                    onIncrease: {
                        CircuitComponentSolver.resistorCr += 1
                    }
                    onDecrease: {
                        if(CircuitComponentSolver.resistorCr > 0)
                            CircuitComponentSolver.resistorCr -= 1
                    }
                }

                MyStyledLabel {
                    id: lblCrCapasitor
                    text: "Capacitor (F):"
                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    MyStyledTextField {
                        id: inputCrCapasitor
                        placeholderText: qsTr("0.000001")
                        //validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*F$/}

                        text: {
                            console.log("inputCrCapasitor::text", CircuitComponentSolver.capasitorCr)
                            return CircuitComponentSolver.capasitorCr
                        }

                        onEditingFinished: {
                            CircuitComponentSolver.capasitorCr = inputCrCapasitor.text
                        }

                        onIncrease: {
                            CircuitComponentSolver.capasitorCr += 1
                        }
                        onDecrease: {
                            if(CircuitComponentSolver.capasitorCr > 0)
                                CircuitComponentSolver.capasitorCr -= 1
                        }
                    }

                    MyStyledComboBox {
                        id: crCapasitorPrefix
                        currentIndex: 2

                        textRole: "text"
                        valueRole: "value"
                        model: root.multiplier_model
                        // model: ["p (pico)", "n (nano)", "µ (micro)", "m (milli)", "(no prefix)", "k (kilo)" ]// "M (mega)", "G (Giga)", "T (Tera)"]

                        onCurrentValueChanged: {
                            CircuitComponentSolver.capasitorMultiplier = crCapasitorPrefix.currentValue
                        }
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

                    text: {
                        console.log("inputCrFrequency::text", CircuitComponentSolver.frequencyCr)
                        return CircuitComponentSolver.frequencyCr
                    }

                    onEditingFinished: {
                        console.log("inputCrFrequency::onEditingFinished", inputCrFrequency.text)
                        CircuitComponentSolver.frequencyCr = parseFloat(inputCrFrequency.text)
                    }

                    onIncrease: {
                        CircuitComponentSolver.frequencyCr += 1
                    }
                    onDecrease: {
                        if(CircuitComponentSolver.frequencyCr > 0)
                            CircuitComponentSolver.frequencyCr -= 1
                    }
                }

                MyStyledLabel {
                    id: lblCrResult
                    text: CircuitComponentSolver.resultCr

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

                    text: {
                        console.log("inputIrResitor::text", CircuitComponentSolver.resistorIr)
                        return CircuitComponentSolver.resistorIr
                    }

                    onEditingFinished: {
                        CircuitComponentSolver.resistorIr = inputIrResitor.text
                    }

                    onIncrease: {
                        CircuitComponentSolver.resistorIr += 1
                    }
                    onDecrease: {
                        if(CircuitComponentSolver.resistorIr > 0)
                            CircuitComponentSolver.resistorIr -= 1
                    }
                }

                MyStyledLabel {
                    id: lblIrInductor
                    text: "Inductor (H):"
                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    MyStyledTextField {
                        id: inputIrInductor
                        placeholderText: qsTr("0.1")
                        //validator: RegularExpressionValidator{regularExpression: /\d+(\.\d+)?\s*H$/}

                        text: {
                            console.log("inputIrInductor::text", CircuitComponentSolver.inductorIr)
                            return CircuitComponentSolver.inductorIr
                        }

                        onEditingFinished: {
                            CircuitComponentSolver.inductorIr = inputIrInductor.text
                        }

                        onIncrease: {
                            CircuitComponentSolver.inductorIr += 1
                        }
                        onDecrease: {
                            if(CircuitComponentSolver.inductorIr > 0)
                                CircuitComponentSolver.inductorIr -= 1
                        }
                    }

                    MyStyledComboBox {
                        id: irInductorPrefix
                        currentIndex: 2

                        textRole: "text"
                        valueRole: "value"
                        model: root.multiplier_model//["p (pico)", "n (nano)", "µ (micro)", "m (milli)", "(no prefix)", "k (kilo)" ]// "M (mega)", "G (Giga)", "T (Tera)"]

                        onCurrentValueChanged: {
                            console.log("irInductorPrefix::onCurrentValueChanged", currentValue)
                            CircuitComponentSolver.inductorMultiplier = irInductorPrefix.currentValue
                        }
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

                    text: {
                        console.log("inputIrFrequency::text", CircuitComponentSolver.frequencyIr)
                        return CircuitComponentSolver.frequencyIr
                    }

                    onEditingFinished: {
                        CircuitComponentSolver.frequencyIr = inputIrFrequency.text
                    }

                    onIncrease: {
                        CircuitComponentSolver.frequencyIr += 1
                    }
                    onDecrease: {
                        if(CircuitComponentSolver.frequencyIr > 0)
                            CircuitComponentSolver.frequencyIr -= 1
                    }
                }

                MyStyledLabel {
                    id: lblIrResult
                    text: CircuitComponentSolver.resultIr

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }
        }
    }
}

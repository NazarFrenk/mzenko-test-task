#include "CircuitComponentSolver.h"

CircuitComponentSolver::CircuitComponentSolver(QObject *parent)
    : QObject{parent}
{

}

CircuitComponentSolver::~CircuitComponentSolver()
{

}

void CircuitComponentSolver::removeLastResistorValue()
{
    if (!m_resistors.empty())
    {
        m_resistors.pop_back();
    }

    QString dataString = createDataResistorsString();

    setDataResistors(dataString);

    recalculateResult();

    qDebug() << "removeLastResistorValue::Resistors count" << m_resistors.size();
}

void CircuitComponentSolver::clearResistorsData()
{
    m_resistors.clear();

    QString dataString = createDataResistorsString();

    setDataResistors(dataString);

    qDebug() << "clearResistorsData::Resistors count" << m_resistors.size();
}

void CircuitComponentSolver::calculateResistance(bool is_parallel)
{
    QString result = "Result: ";

    if (is_parallel){
        result += calculateParallelResistance();
    } else {
        result += calculateSeriesResistance();
    }

    setResultResistors(result);
}

QString CircuitComponentSolver::createDataResistorsString()
{
    if (m_resistors.empty())
    {
        return "Data: no data";
    }

    QString dataStr = "Data: ";

    for (const auto &value: m_resistors) {
        dataStr += QString("%1, ").arg(value, 0, 'f', 5);
    }

    dataStr.chop(2); // remove last ", "

    return dataStr;
}

QString CircuitComponentSolver::calculateSeriesResistance()
{
    if (m_resistors.empty())
    {
        return "no data";
    }

    float total_resistance = 0;

    for (const auto &value: m_resistors) {
        total_resistance += value;
    }

    return QString("%1 Ω").arg(total_resistance, 0, 'f', 5);
}

QString CircuitComponentSolver::calculateParallelResistance()
{
    if (m_resistors.empty())
    {
        return "no data";
    }

    float total_resistance = 0;

    for (const auto &value: m_resistors) {
        total_resistance += 1/value;
    }

    total_resistance = 1/total_resistance;

    return QString("%1 Ω").arg(total_resistance, 0, 'f', 5);
}

QString CircuitComponentSolver::calculateCRImpedance()
{
    float imaginary = 1 / (2 * M_PI * m_frequencyCr * m_capasitorCr * m_capasitorMultiplier);

    return QString("%1 + j%2 Ω").arg(m_resistorCr, 0, 'f', 5).arg(imaginary, 0, 'f', 5);
}

QString CircuitComponentSolver::calculateIRImpedance()
{
    float imaginary = 2 * M_PI * m_frequencyIr * m_inductorIr * m_inductorMultiplier;

    return QString("%1 + j%2 Ω").arg(m_resistorIr, 0, 'f', 5).arg(imaginary, 0, 'f', 5);
}

bool CircuitComponentSolver::isParallel() const
{
    return m_isParallel;
}

void CircuitComponentSolver::setIsParallel(bool newIsParallel)
{
    if (m_isParallel == newIsParallel)
        return;
    m_isParallel = newIsParallel;
    emit isParallelChanged();

    recalculateResult();
}

float CircuitComponentSolver::resistorValue() const
{
    return m_resistorValue;
}

QString CircuitComponentSolver::data() const
{
    return m_dataResistors;
}

void CircuitComponentSolver::setDataResistors(const QString &newDataResistors)
{
    if (m_dataResistors == newDataResistors)
        return;
    m_dataResistors = newDataResistors;
    emit dataResistorsChanged();
}

QString CircuitComponentSolver::result() const
{
    return m_resultResistors;
}

void CircuitComponentSolver::setResistorValue(float newResistorValue)
{
    if (m_resistorValue == newResistorValue)
        return;

    m_resistorValue = newResistorValue;

    emit resistorValueChanged();

    addNewResistor();

    recalculateResult();
}

void CircuitComponentSolver::addNewResistor()
{
    if (m_resistorValue > 0)
    {
        m_resistors.push_back(m_resistorValue);

        QString dataString = createDataResistorsString();

        setDataResistors(dataString);
    }
}

void CircuitComponentSolver::setResultResistors(const QString &newResultResistors)
{
    if (m_resultResistors == newResultResistors)
        return;
    m_resultResistors = newResultResistors;
    emit resultResistorsChanged();
}

float CircuitComponentSolver::resistorCR() const
{
    return m_resistorCr;
}

void CircuitComponentSolver::setResistorCr(const float &newResistorCr)
{
    if (qIsNaN(newResistorCr))
        return;

    if (m_resistorCr == newResistorCr)
        return;
    m_resistorCr = newResistorCr;

    if (newResistorCr > 0)
    {
        m_resistorCr = newResistorCr;
    }

    emit resistorCrChanged();

    recalculateResult();
}

float CircuitComponentSolver::capasitorCr() const
{
    return m_capasitorCr;
}

void CircuitComponentSolver::setCapasitorCr(const float &newCapasitorCr)
{
    if (qIsNaN(newCapasitorCr))
        return;

    if (m_capasitorCr == newCapasitorCr)
        return;
    m_capasitorCr = newCapasitorCr;

    if (newCapasitorCr > 0)
    {
        m_capasitorCr = newCapasitorCr;
    }

    emit capasitorCrChanged();

    recalculateResult();
}

float CircuitComponentSolver::capasitorMultiplier() const
{
    return m_capasitorMultiplier;
}

void CircuitComponentSolver::setCapasitorMultiplier(float newCapasitorMultiplier)
{
    if (m_capasitorMultiplier == newCapasitorMultiplier)
        return;
    m_capasitorMultiplier = newCapasitorMultiplier;
    emit capasitorMultiplierChanged();

    recalculateResult();
}

float CircuitComponentSolver::frequencyCr() const
{
    return m_frequencyCr;
}

void CircuitComponentSolver::setFrequencyCr(const float &newFrequencyCr)
{
    if (qIsNaN(newFrequencyCr))
        return;

    if (m_frequencyCr == newFrequencyCr)
        return;
    m_frequencyCr = newFrequencyCr;

    emit frequencyCrChanged();

    recalculateResult();
}

QString CircuitComponentSolver::resultCr() const
{
    return m_resultCr;
}

void CircuitComponentSolver::setResultCr(const QString &newResultCr)
{
    if (m_resultCr == newResultCr)
        return;
    m_resultCr = newResultCr;
    emit resultCrChanged();

    recalculateResult();
}

void CircuitComponentSolver::calculateCrResult()
{
    QString result = "Result Impedance: ";

    if (m_resistorCr && m_capasitorCr && m_frequencyCr)
    {
        result += calculateCRImpedance();
    }
    else
    {
        result += "no data";
    }

    setResultCr(result);
}

float CircuitComponentSolver::resistorIr() const
{
    return m_resistorIr;
}

void CircuitComponentSolver::setResistorIr(const float &newResistorIr)
{
    if (qIsNaN(newResistorIr))
        return;

    if (m_resistorIr == newResistorIr)
        return;
    m_resistorIr = newResistorIr;

    if (newResistorIr > 0)
    {
        m_resistorIr = newResistorIr;
    }

    emit resistorIrChanged();

    recalculateResult();
}

float CircuitComponentSolver::inductorIr() const
{
    return m_inductorIr;
}

void CircuitComponentSolver::setInductorIr(const float &newInductorIr)
{
    if (qIsNaN(newInductorIr))
        return;

    if (m_inductorIr == newInductorIr)
        return;
    m_inductorIr = newInductorIr;

    if (newInductorIr > 0)
    {
        m_inductorIr = newInductorIr;
    }

    emit inductorIrChanged();

    recalculateResult();
}

float CircuitComponentSolver::inductorMultiplier() const
{
    return m_inductorMultiplier;
}

void CircuitComponentSolver::setInductorMultiplier(float newInductorMultiplier)
{
    if (m_inductorMultiplier == newInductorMultiplier)
        return;
    m_inductorMultiplier = newInductorMultiplier;
    emit inductorMultiplierChanged();

    recalculateResult();
}

float CircuitComponentSolver::frequencyIr() const
{
    return m_frequencyIr;
}

void CircuitComponentSolver::setFrequencyIr(const float &newFrequencyIr)
{
    if (qIsNaN(newFrequencyIr))
        return;

    if (m_frequencyIr == newFrequencyIr)
        return;
    m_frequencyIr = newFrequencyIr;

    if (newFrequencyIr > 0)
    {
        m_frequencyIr = newFrequencyIr;
    }

    emit frequencyIrChanged();

    recalculateResult();
}

QString CircuitComponentSolver::resultIr() const
{
    return m_resultIr;
}

void CircuitComponentSolver::setResultIr(const QString &newResultIr)
{
    if (m_resultIr == newResultIr)
        return;
    m_resultIr = newResultIr;
    emit resultIrChanged();
}

void CircuitComponentSolver::createIrResult()
{
    QString result = "Result Impedance: ";

    if (m_resistorIr && m_inductorIr && m_frequencyIr)
    {
        result += calculateIRImpedance();
    }
    else
    {
        result += "no data";
    }

    setResultIr(result);
}

void CircuitComponentSolver::setCurrentTapIndex(int val)
{
    if(m_currentTapIndex == val)
        return;

    m_currentTapIndex = val;
    emit currentTapIndexChanged();
}

void CircuitComponentSolver::recalculateResult()
{
    qInfo() << "CircuitComponentSolver::recalculateResult for" << m_currentTapIndex;

    switch (m_currentTapIndex) {
    case 0:
        calculateResistance(m_isParallel);
        return;
    case 1:
        calculateCrResult();
        return;
    case 2:
        createIrResult();
        return;
    }

    qWarning() << "CircuitComponentSolver::recalculateResult value" << m_currentTapIndex << "not handled in switch";

    Q_UNREACHABLE();
}

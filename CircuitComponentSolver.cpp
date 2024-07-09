#include "CircuitComponentSolver.h"

CircuitComponentSolver::CircuitComponentSolver(QObject *parent)
    : QObject{parent}
{
    m_resistors = new std::deque<float>();
}

CircuitComponentSolver::~CircuitComponentSolver()
{
    delete m_resistors;
}

void CircuitComponentSolver::removeLastResistorValue()
{
    if (!m_resistors->empty())
    {
        m_resistors->pop_back();
    }

    QString dataString = createDataResistorsString();

    setDataResistors(dataString);

    qDebug() << "removeLastResistorValue::Resistors count" << m_resistors->size();
}

void CircuitComponentSolver::clearResistorsData()
{
    m_resistors->clear();

    QString dataString = createDataResistorsString();

    setDataResistors(dataString);

    qDebug() << "clearResistorsData::Resistors count" << m_resistors->size();
}

void CircuitComponentSolver::calculateResistance(int type)
{
    QString result = "Result: ";

    if (type == 0)
    {
        result += calculateSeriesResistance();
    }
    else
    {
        result += calculateParallelResistance();
    }

    setResultResistors(result);
}

QString CircuitComponentSolver::createDataResistorsString()
{
    if (m_resistors->empty())
    {
        return "Data: no data";
    }

    QString dataStr = "Data: ";

    for (float value: *m_resistors) {
        dataStr += QString("%1, ").arg(value, 0, 'f', 5);
    }

    dataStr.chop(2); // remove last ", "

    return dataStr;
}

QString CircuitComponentSolver::calculateSeriesResistance()
{
    if (m_resistors->empty())
    {
        return "no data";
    }

    float total_resistance = 0;

    for (float value: *m_resistors) {
        total_resistance += value;
    }

    return QString("%1 Ω").arg(total_resistance, 0, 'f', 5);
}

QString CircuitComponentSolver::calculateParallelResistance()
{
    if (m_resistors->empty())
    {
        return "no data";
    }

    float total_resistance = 0;

    for (float value: *m_resistors) {
        total_resistance += 1/value;
    }

    total_resistance = 1/total_resistance;

    return QString("%1 Ω").arg(total_resistance, 0, 'f', 5);
}

QString CircuitComponentSolver::calculateCRImpedance()
{
    float imaginary = 1 / (2 * M_PI * m_frequency * m_capacitor);

    return QString("%1 + j%2 Ω").arg(m_resistor, 0, 'f', 5).arg(imaginary, 0, 'f', 5);
}

QString CircuitComponentSolver::calculateIRImpedance()
{
    float imaginary = 2 * M_PI * m_frequency * m_inductor;

    return QString("%1 + j%2 Ω").arg(m_resistor, 0, 'f', 5).arg(imaginary, 0, 'f', 5);
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

void CircuitComponentSolver::setResistorValue(const float &newResistorValue)
{
    if (qIsNaN(newResistorValue))
    {
        m_resistor = -1; // wrong input
        return;
    }

    qDebug() << "CircuitComponentSolver::setResistorValue" << "check for update";
    if (m_resistor == newResistorValue)
        return;
    m_resistor = newResistorValue;

    emit resistorValueChanged();
}

void CircuitComponentSolver::addNewResistor()
{
    if (m_resistor > 0)
    {
        m_resistors->push_back(m_resistor);

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

    if (m_resistor == newResistorCr)
        return;
    m_resistor = newResistorCr;

    if (newResistorCr > 0)
    {
        m_resistor = newResistorCr;
    }

    emit resistorCrChanged();
}

float CircuitComponentSolver::capasitorCr() const
{
    return m_capasitorCr;
}

void CircuitComponentSolver::setCapasitorCr(const float &newCapasitorCr)
{
    if (qIsNaN(newCapasitorCr))
        return;

    if (m_capacitor == newCapasitorCr)
        return;
    m_capacitor = newCapasitorCr;

    if (newCapasitorCr > 0)
    {
        m_capacitor = newCapasitorCr;
    }

    emit capasitorCrChanged();
}

float CircuitComponentSolver::frequencyCr() const
{
    return m_frequencyCr;
}

void CircuitComponentSolver::setFrequencyCr(const float &newFrequencyCr)
{
    if (qIsNaN(newFrequencyCr))
        return;

    if (m_frequency == newFrequencyCr)
        return;
    m_frequency = newFrequencyCr;

    if (newFrequencyCr > 0)
    {
        m_frequency = newFrequencyCr;
    }

    emit frequencyCrChanged();
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
}

void CircuitComponentSolver::createCrResult()
{
    QString result = "Result Impedance: ";

    if (m_resistor && m_capacitor && m_frequency)
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

    if (m_resistor == newResistorIr)
        return;
    m_resistor = newResistorIr;

    if (newResistorIr > 0)
    {
        m_resistor = newResistorIr;
    }

    emit resistorIrChanged();
}

float CircuitComponentSolver::inductorIr() const
{
    return m_inductorIr;
}

void CircuitComponentSolver::setInductorIr(const float &newInductorIr)
{
    if (qIsNaN(newInductorIr))
        return;

    if (m_inductor == newInductorIr)
        return;
    m_inductor = newInductorIr;

    if (newInductorIr > 0)
    {
        m_inductor = newInductorIr;
    }

    emit inductorIrChanged();
}

float CircuitComponentSolver::frequencyIr() const
{
    return m_frequencyIr;
}

void CircuitComponentSolver::setFrequencyIr(const float &newFrequencyIr)
{
    if (qIsNaN(newFrequencyIr))
        return;

    if (m_frequency == newFrequencyIr)
        return;
    m_frequency = newFrequencyIr;

    if (newFrequencyIr > 0)
    {
        m_frequency = newFrequencyIr;
    }

    emit frequencyIrChanged();
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

    if (m_resistor && m_inductor && m_frequency)
    {
        result += calculateIRImpedance();
    }
    else
    {
        result += "no data";
    }

    setResultIr(result);
}

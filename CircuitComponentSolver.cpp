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

QString CircuitComponentSolver::calculateLRImpedance()
{
    float imaginary = 2 * M_PI * m_frequency * m_inductor;

    return QString("%1 + j%2 Ω").arg(m_resistor, 0, 'f', 5).arg(imaginary, 0, 'f', 5);
}

QString CircuitComponentSolver::resistorValue() const
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

void CircuitComponentSolver::setResistorValue(const QString &newResistorValue)
{
    float value = newResistorValue.toFloat();

    if (value > 0)
    {
        m_resistors->push_back(value);

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

QString CircuitComponentSolver::resistorCR() const
{
    return m_resistorCr;
}

void CircuitComponentSolver::setResistorCr(const QString &newResistorCr)
{
    float value = newResistorCr.toFloat();

    if (value > 0)
    {
        m_resistor = value;
    }
}

QString CircuitComponentSolver::capasitorCr() const
{
    return m_capasitorCr;
}

void CircuitComponentSolver::setCapasitorCr(const QString &newCapasitorCr)
{
    float value = newCapasitorCr.toFloat();

    if (value > 0)
    {
        m_capacitor = value;
    }
}

QString CircuitComponentSolver::frequencyCr() const
{
    return m_frequencyCr;
}

void CircuitComponentSolver::setFrequencyCr(const QString &newFrequencyCr)
{
    float value = newFrequencyCr.toFloat();

    if (value > 0)
    {
        m_frequency = value;
    }
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

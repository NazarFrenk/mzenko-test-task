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

    // TODO - update result label
}

void CircuitComponentSolver::clearResistorsData()
{
    m_resistors->clear();

    // TODO - update result label
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

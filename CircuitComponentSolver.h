#ifndef CIRCUITCOMPONENTSOLVER_H
#define CIRCUITCOMPONENTSOLVER_H

#include <QObject>
#include <deque>

class CircuitComponentSolver : public QObject
{
    Q_OBJECT
public:
    explicit CircuitComponentSolver(QObject *parent = nullptr);
    ~CircuitComponentSolver();

signals:

private:
    std::deque<float> *m_resistors = nullptr; // list of resistors for resistor tab
    float m_resistor;
    float m_capacitor;
    float m_inductor;
    float m_frequency;

    QString calculateSeriesResistance();
    QString calculateParallelResistance();
    QString calculateCRImpedance();
    QString calculateLRImpedance();
};

#endif // CIRCUITCOMPONENTSOLVER_H

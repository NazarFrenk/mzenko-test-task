#ifndef CIRCUITCOMPONENTSOLVER_H
#define CIRCUITCOMPONENTSOLVER_H

#include <QObject>
#include <QDebug>
#include <deque>

class CircuitComponentSolver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString resistorValue READ resistorValue WRITE setResistorValue NOTIFY resistorValueChanged FINAL)
    Q_PROPERTY(QString dataResistors READ data WRITE setDataResistors NOTIFY dataResistorsChanged FINAL)
    Q_PROPERTY(QString resultResistors READ result WRITE setResultResistors NOTIFY resultResistorsChanged FINAL)

public:
    explicit CircuitComponentSolver(QObject *parent = nullptr);
    ~CircuitComponentSolver();

    QString resistorValue() const;

    QString data() const;

    QString result() const;

public slots:
    void setResistorValue(const QString &newResistorValue);
    void setDataResistors(const QString &newDataResistors);
    void removeLastResistorValue();
    void clearResistorsData();
    void setResultResistors(const QString &newResultResistors);
    void calculateResistance(int type);

signals:

    void resistorValueChanged();

    void dataResistorsChanged();

    void resultResistorsChanged();

private:
    std::deque<float> *m_resistors = nullptr; // list of resistors for resistor tab
    float m_resistor;
    float m_capacitor;
    float m_inductor;
    float m_frequency;

    QString createDataResistorsString();
    QString calculateSeriesResistance();
    QString calculateParallelResistance();
    QString calculateCRImpedance();
    QString calculateLRImpedance();
    QString m_resistorValue;
    QString m_dataResistors;
    QString m_resultResistors;
};

#endif // CIRCUITCOMPONENTSOLVER_H

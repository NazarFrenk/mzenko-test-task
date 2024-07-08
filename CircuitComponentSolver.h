#ifndef CIRCUITCOMPONENTSOLVER_H
#define CIRCUITCOMPONENTSOLVER_H

#include <QObject>
#include <QDebug>
#include <deque>

class CircuitComponentSolver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float resistorValue READ resistorValue WRITE setResistorValue NOTIFY resistorValueChanged FINAL)
    Q_PROPERTY(QString dataResistors READ data WRITE setDataResistors NOTIFY dataResistorsChanged FINAL)
    Q_PROPERTY(QString resultResistors READ result WRITE setResultResistors NOTIFY resultResistorsChanged FINAL)

    Q_PROPERTY(float resistorCr READ resistorCR WRITE setResistorCr NOTIFY resistorCrChanged FINAL)
    Q_PROPERTY(float capasitorCr READ capasitorCr WRITE setCapasitorCr NOTIFY capasitorCrChanged FINAL)
    Q_PROPERTY(float frequencyCr READ frequencyCr WRITE setFrequencyCr NOTIFY frequencyCrChanged FINAL)
    Q_PROPERTY(QString resultCr READ resultCr WRITE setResultCr NOTIFY resultCrChanged FINAL)

    Q_PROPERTY(float resistorIr READ resistorIr WRITE setResistorIr NOTIFY resistorIrChanged FINAL)
    Q_PROPERTY(float inductorIr READ inductorIr WRITE setInductorIr NOTIFY inductorIrChanged FINAL)
    Q_PROPERTY(float frequencyIr READ frequencyIr WRITE setFrequencyIr NOTIFY frequencyIrChanged FINAL)
    Q_PROPERTY(QString resultIr READ resultIr WRITE setResultIr NOTIFY resultIrChanged FINAL)

public:
    explicit CircuitComponentSolver(QObject *parent = nullptr);
    ~CircuitComponentSolver();

    float resistorValue() const;

    QString data() const;

    QString result() const;

    float resistorCR() const;

    float capasitorCr() const;

    float frequencyCr() const;

    QString resultCr() const;

    float resistorIr() const;

    float inductorIr() const;

    float frequencyIr() const;

    QString resultIr() const;

public slots:
    void setResistorValue(const float &newResistorValue);
    void setDataResistors(const QString &newDataResistors);
    void removeLastResistorValue();
    void clearResistorsData();
    void setResultResistors(const QString &newResultResistors);
    void calculateResistance(int type);

    void setResistorCr(const float &newResistorCr);
    void setCapasitorCr(const float &newCapasitorCr);
    void setFrequencyCr(const float &newFrequencyCr);
    void setResultCr(const QString &newResultCr);
    void createCrResult();

    void setResistorIr(const float &newResistorIr);
    void setInductorIr(const float &newInductorIr);
    void setFrequencyIr(const float &newFrequencyIr);
    void setResultIr(const QString &newResultIr);
    void createIrResult();

signals:

    void resistorValueChanged();
    void dataResistorsChanged();
    void resultResistorsChanged();
    void resistorCrChanged();
    void capasitorCrChanged();
    void frequencyCrChanged();
    void resultCrChanged();
    void resistorIrChanged();
    void inductorIrChanged();
    void frequencyIrChanged();
    void resultIrChanged();

private:
    std::deque<float> *m_resistors = nullptr; // list of resistors for resistor tab
    float m_resistor = 0;
    float m_capacitor = 0;
    float m_inductor = 0;
    float m_frequency = 0;

    QString createDataResistorsString();
    QString calculateSeriesResistance();
    QString calculateParallelResistance();
    QString calculateCRImpedance();
    QString calculateIRImpedance();
    float m_resistorValue;
    QString m_dataResistors = "Data: no data";
    QString m_resultResistors = "Result: no data";
    float m_resistorCr;
    float m_capasitorCr;
    float m_frequencyCr;
    QString m_resultCr = "Result Impedance: no data";
    float m_resistorIr;
    float m_inductorIr;
    float m_frequencyIr;
    QString m_resultIr = "Result Impedance: no data";
};

#endif // CIRCUITCOMPONENTSOLVER_H

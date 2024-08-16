#ifndef CIRCUITCOMPONENTSOLVER_H
#define CIRCUITCOMPONENTSOLVER_H

#include <QObject>
#include <QtNumeric>
#include <QDebug>
#include <deque>

class CircuitComponentSolver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isParallel READ isParallel WRITE setIsParallel NOTIFY isParallelChanged FINAL)
    Q_PROPERTY(float resistorValue READ resistorValue WRITE setResistorValue NOTIFY resistorValueChanged FINAL)
    Q_PROPERTY(QString dataResistors READ data NOTIFY dataResistorsChanged FINAL)
    Q_PROPERTY(QString resultResistors READ result NOTIFY resultResistorsChanged FINAL)

    Q_PROPERTY(float resistorCr READ resistorCR WRITE setResistorCr NOTIFY resistorCrChanged FINAL)
    Q_PROPERTY(float capasitorCr READ capasitorCr WRITE setCapasitorCr NOTIFY capasitorCrChanged FINAL)
    Q_PROPERTY(float capasitorMultiplier READ capasitorMultiplier WRITE setCapasitorMultiplier NOTIFY capasitorMultiplierChanged FINAL)
    Q_PROPERTY(float frequencyCr READ frequencyCr WRITE setFrequencyCr NOTIFY frequencyCrChanged FINAL)
    Q_PROPERTY(QString resultCr READ resultCr NOTIFY resultCrChanged FINAL)

    Q_PROPERTY(float resistorIr READ resistorIr WRITE setResistorIr NOTIFY resistorIrChanged FINAL)
    Q_PROPERTY(float inductorIr READ inductorIr WRITE setInductorIr NOTIFY inductorIrChanged FINAL)
    Q_PROPERTY(float inductorMultiplier READ inductorMultiplier WRITE setInductorMultiplier NOTIFY inductorMultiplierChanged FINAL)
    Q_PROPERTY(float frequencyIr READ frequencyIr WRITE setFrequencyIr NOTIFY frequencyIrChanged FINAL)
    Q_PROPERTY(QString resultIr READ resultIr NOTIFY resultIrChanged FINAL)

    Q_PROPERTY(int currentTapIndex WRITE setCurrentTapIndex NOTIFY currentTapIndexChanged FINAL)

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

    bool isParallel() const;

    float capasitorMultiplier() const;

    float inductorMultiplier() const;

public slots:
    void setIsParallel(bool newIsParallel);
    void setResistorValue(float newResistorValue);
    void addNewResistor();
    void setDataResistors(const QString &newDataResistors);
    void removeLastResistorValue();
    void clearResistorsData();
    void setResultResistors(const QString &newResultResistors);
    void calculateResistance(bool is_parallel);

    void setResistorCr(const float &newResistorCr);
    void setCapasitorCr(const float &newCapasitorCr);
    void setCapasitorMultiplier(float newCapsitorMultiplier);
    void setFrequencyCr(const float &newFrequencyCr);
    void setResultCr(const QString &newResultCr);
    void calculateCrResult();

    void setResistorIr(const float &newResistorIr);
    void setInductorIr(const float &newInductorIr);
    void setInductorMultiplier(float newInductorMultiplier);
    void setFrequencyIr(const float &newFrequencyIr);
    void setResultIr(const QString &newResultIr);
    void createIrResult();

    void setCurrentTapIndex(int val);

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

    void currentTapIndexChanged();

    void isParallelChanged();

    void capasitorMultiplierChanged();

    void inductorMultiplierChanged();

private:
    void recalculateResult();

    std::deque<float> m_resistors; // list of resistors for resistor tab

    QString createDataResistorsString();
    QString calculateSeriesResistance();
    QString calculateParallelResistance();
    QString calculateCRImpedance();
    QString calculateIRImpedance();
    bool m_isParallel = true;
    float m_resistorValue = 0;
    QString m_dataResistors = "Data: no data";
    QString m_resultResistors = "Result: no data";
    float m_resistorCr = 0;
    float m_capasitorCr = 0;
    float m_capasitorMultiplier = 1;
    float m_frequencyCr = 0;
    QString m_resultCr = "Result Impedance: no data";
    float m_resistorIr = 0;
    float m_inductorIr = 0;
    float m_inductorMultiplier = 1;
    float m_frequencyIr = 0;
    QString m_resultIr = "Result Impedance: no data";

    int m_currentTapIndex = 0;
};

#endif // CIRCUITCOMPONENTSOLVER_H

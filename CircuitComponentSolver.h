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

    Q_PROPERTY(QString resistorCr READ resistorCR WRITE setResistorCr NOTIFY resistorCrChanged FINAL)
    Q_PROPERTY(QString capasitorCr READ capasitorCr WRITE setCapasitorCr NOTIFY capasitorCrChanged FINAL)
    Q_PROPERTY(QString frequencyCr READ frequencyCr WRITE setFrequencyCr NOTIFY frequencyCrChanged FINAL)
    Q_PROPERTY(QString resultCr READ resultCr WRITE setResultCr NOTIFY resultCrChanged FINAL)

    Q_PROPERTY(QString resistorIr READ resistorIr WRITE setResistorIr NOTIFY resistorIrChanged FINAL)
    Q_PROPERTY(QString inductorIr READ inductorIr WRITE setInductorIr NOTIFY inductorIrChanged FINAL)
    Q_PROPERTY(QString frequencyIr READ frequencyIr WRITE setFrequencyIr NOTIFY frequencyIrChanged FINAL)
    Q_PROPERTY(QString resultIr READ resultIr WRITE setResultIr NOTIFY resultIrChanged FINAL)

public:
    explicit CircuitComponentSolver(QObject *parent = nullptr);
    ~CircuitComponentSolver();

    float resistorValue() const;

    QString data() const;

    QString result() const;

    QString resistorCR() const;

    QString capasitorCr() const;

    QString frequencyCr() const;

    QString resultCr() const;

    QString resistorIr() const;

    QString inductorIr() const;

    QString frequencyIr() const;

    QString resultIr() const;

public slots:
    void setResistorValue(const float &newResistorValue);
    void setDataResistors(const QString &newDataResistors);
    void removeLastResistorValue();
    void clearResistorsData();
    void setResultResistors(const QString &newResultResistors);
    void calculateResistance(int type);

    void setResistorCr(const QString &newResistorCr);
    void setCapasitorCr(const QString &newCapasitorCr);
    void setFrequencyCr(const QString &newFrequencyCr);
    void setResultCr(const QString &newResultCr);
    void createCrResult();

    void setResistorIr(const QString &newResistorIr);
    void setInductorIr(const QString &newInductorIr);
    void setFrequencyIr(const QString &newFrequencyIr);
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
    QString m_dataResistors;
    QString m_resultResistors;
    QString m_resistorCr;
    QString m_capasitorCr;
    QString m_frequencyCr;
    QString m_resultCr;
    QString m_resistorIr;
    QString m_inductorIr;
    QString m_frequencyIr;
    QString m_resultIr;
};

#endif // CIRCUITCOMPONENTSOLVER_H

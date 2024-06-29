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

    Q_PROPERTY(QString resistorCr READ resistorCR WRITE setResistorCr NOTIFY resistorCrChanged FINAL)
    Q_PROPERTY(QString capasitorCr READ capasitorCr WRITE setCapasitorCr NOTIFY capasitorCrChanged FINAL)
    Q_PROPERTY(QString frequencyCr READ frequencyCr WRITE setFrequencyCr NOTIFY frequencyCrChanged FINAL)
    Q_PROPERTY(QString resultCr READ resultCr WRITE setResultCr NOTIFY resultCrChanged FINAL)

public:
    explicit CircuitComponentSolver(QObject *parent = nullptr);
    ~CircuitComponentSolver();

    QString resistorValue() const;

    QString data() const;

    QString result() const;

    QString resistorCR() const;

    QString capasitorCr() const;

    QString frequencyCr() const;

    QString resultCr() const;

public slots:
    void setResistorValue(const QString &newResistorValue);
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

signals:

    void resistorValueChanged();
    void dataResistorsChanged();
    void resultResistorsChanged();
    void resistorCrChanged();
    void capasitorCrChanged();
    void frequencyCrChanged();
    void resultCrChanged();

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
    QString calculateLRImpedance();
    QString m_resistorValue;
    QString m_dataResistors;
    QString m_resultResistors;
    QString m_resistorCr;
    QString m_capasitorCr;
    QString m_frequencyCr;
    QString m_resultCr;
};

#endif // CIRCUITCOMPONENTSOLVER_H

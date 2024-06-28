#ifndef CIRCUITCOMPONENTSOLVER_H
#define CIRCUITCOMPONENTSOLVER_H

#include <QObject>

class CircuitComponentSolver : public QObject
{
    Q_OBJECT
public:
    explicit CircuitComponentSolver(QObject *parent = nullptr);

signals:
};

#endif // CIRCUITCOMPONENTSOLVER_H

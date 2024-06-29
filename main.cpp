#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CircuitComponentSolver.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    CircuitComponentSolver *solver = new CircuitComponentSolver(&app);
    qmlRegisterSingletonInstance("CircuitComponentSolver", 1, 0, "CircuitComponentSolver", solver);

    const QUrl url(QStringLiteral("qrc:/QtQmlResonantCalc/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>

QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QQmlEngine engine;
        QQmlContext *objectContext = new QQmlContext(engine.rootContext());

        QQmlComponent component(&engine, "main.qml");
        QObject *object = component.create(objectContext);
    MainWindow w;
    w.show();
    return a.exec();
}

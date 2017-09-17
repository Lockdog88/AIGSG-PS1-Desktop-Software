#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtQml/QQmlApplicationEngine>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //Q_INVOKABLE void FunctionC();//Функция C++ вызываемая из QML

private slots:
    void on_OpenPort_clicked();
    void on_ClosePort_clicked();
    void readData();
    void readRelayData();
    void readGNSS();
    void readPATH(QByteArray data);
    float Nmea2Dec(char * nmea, char type);

    void on_horizontalSlider_valueChanged(int value);

    void on_sendButton_clicked();

    void on_actionMap_VIewer_triggered();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_zoomScrollBar_valueChanged(int value);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_SaveLog_clicked();

    void on_pushButton_SaveLogTag3_clicked();

    void on_pushButton_SaveLogSens_clicked();

private:
    QQmlApplicationEngine *engine;
    Ui::MainWindow *ui;
    QSerialPort *serial;

    unsigned short calculateCRC16(uint8_t input[], int lenght);
};

#endif // MAINWINDOW_H

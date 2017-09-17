#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QWindow>
#include <QtPositioning>
#include <QFileDialog>
#include <QTextStream>



QT_USE_NAMESPACE

#define MAX_LONGITUDE    180
#define MAX_LATITUDE     90

QByteArray packet;
QByteArray pattern("\x40\x61\x67\x6E\x65\x74");


char buf[100] = {0};
char buf_gnss[50] = {0};
int count = 0;
int mode_flag = 0;
int st = 0;
int sens_num = 0;
int sens_num2 = 0;
bool done = false;
bool doneRelay = false;

char state, time[11], header[7], lat[10], longt[11], rssi[5], snr[4];

const unsigned int SHIFTER = 0x00FF;



unsigned short crc16table[256] = {
        0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
        0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022,
        0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072,
        0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041,
        0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8, 0x80DD, 0x80D7, 0x00D2,
        0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1,
        0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1,
        0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
        0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192,
        0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1,
        0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1,
        0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2,
        0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151,
        0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162,
        0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
        0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101,
        0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312,
        0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321,
        0x0360, 0x8365, 0x836F, 0x036A, 0x837B, 0x037E, 0x0374, 0x8371,
        0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342,
        0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1,
        0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
        0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2,
        0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381,
        0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291,
        0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2,
        0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2,
        0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1,
        0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
        0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261,
        0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231,
        0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QCoreApplication::addLibraryPath("C:/some/other/path");

        QStringList paths = QCoreApplication::libraryPaths();
        paths.append(".");
        paths.append("imageformats");
        paths.append("platforms");
        paths.append("plugins");
        paths.append("qml");
        paths.append("QtLocation");
        paths.append("QtPositioning");
        paths.append("QtQml");
        paths.append("QtQuick");
        paths.append("QtQuick.2");
        QCoreApplication::setLibraryPaths(paths);

    ui->setupUi(this);
    serial = new QSerialPort(this);
    ui->parkingLabel->setText("FREE");
    ui->parkingLabel->setStyleSheet("QLabel { color : Green; }");
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
              ui->serialPortComboBox->addItem(info.portName());

    engine = new QQmlApplicationEngine;
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    QWindow *qmlWindow = qobject_cast<QWindow*>(engine->rootObjects().at(0));
    QWidget *container = QWidget::createWindowContainer(qmlWindow);
    ui->verticalLayout->addWidget(container);

    //connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);



    QStringList m_TableHeader;
    m_TableHeader<<"Sensor ID"<<"Status"<<"Battery"<<"RSSI"<<"SNR";
    ui->tableWidget->setHorizontalHeaderLabels(m_TableHeader);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->comboBox->addItem("ON");
    ui->comboBox->addItem("OFF");

    QStringList m_TableHeader2;
    m_TableHeader2<<"Sensor ID"<<"Relay Status"<<"ACK"<<"RSSI"<<"SNR";
    ui->tableSensors->setHorizontalHeaderLabels(m_TableHeader2);
    ui->tableSensors->horizontalHeader()->setVisible(true);
    for (int i=0; i<ui->tableWidget->rowCount(); i++){
        for (int j=0; j<ui->tableWidget->columnCount(); j++){
            ui->tableWidget->setItem(i,j, new QTableWidgetItem(" "));
        }
    }

    for (int i=0; i<ui->tableSensors->rowCount(); i++){
        for (int j=0; j<ui->tableSensors->columnCount(); j++){
            ui->tableSensors->setItem(i,j, new QTableWidgetItem(" "));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenPort_clicked()
{
    serial->setPortName(ui->serialPortComboBox->currentText());
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);

    if (serial->open(QIODevice::ReadWrite))
    {
        if (mode_flag==0) {
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::readRelayData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readGNSS);
        }
        if (mode_flag==1) {
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readRelayData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readGNSS);
        }
        if (mode_flag==2) {
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::readGNSS);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readRelayData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
        }
        ui->portStatusLabel->setText("Port Open");
        ui->portStatusLabel->setStyleSheet("QLabel { color : Green; }");
        ui->sendButton->setEnabled(true);
        ui->commandEdit->setEnabled(true);
        ui->OpenPort->setEnabled(false);
        ui->ClosePort->setEnabled(true);
    }
}

void MainWindow::on_ClosePort_clicked()
{
    if (serial->isOpen())
    {
        serial->close();
        ui->portStatusLabel->setText("Port Closed");
        ui->portStatusLabel->setStyleSheet("QLabel { color : Red; }");
        ui->sendButton->setEnabled(false);
        ui->commandEdit->setEnabled(false);
        ui->OpenPort->setEnabled(true);
        ui->ClosePort->setEnabled(false);
    }
}

QByteArray getPart(const QByteArray message, int part, bool toEnd)
  {
    int characters(toEnd ? -1 : message.indexOf(',', part) - part);

    return message.mid(part, characters);
  }
QByteArray data1(0);
QByteArray data2(0);

//Function for read packets from ParkingSensor over Lora
void MainWindow::readData()
{
    if (!done){
    data1.append(serial->readAll());
    if (data1.data()[data1.size()-1] == '\n') done=true;
    }
    //QByteArray data = serial->readLine(50);
    //disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    if (done){
    //ui->consoleText->insertPlainText(data1);
    QList<QByteArray> doubles = data1.split(',');
    if (doubles.size()>6){
    if ((doubles[0].toInt()==ui->startByteEdit->text().toInt(NULL, 16))&&(doubles[4].toInt()==ui->endByteEdit->text().toInt(NULL, 16)))
    {
        QTime current = QDateTime::currentDateTime().time();
        ui->consoleText->insertPlainText("["+current.toString()+"."+QString::number(current.msec())+"]: "+data1);
        ui->consoleText->verticalScrollBar()->setValue(ui->consoleText->verticalScrollBar()->maximum());
        ui->sensorAddressLabel->setText((QString)doubles[1]);
        QString batt = QString::number(doubles[3].toInt(), 16);
        ui->batteryStatusLabel->setText("0x"+batt);
        ui->batteryBar->setMaximum(130);
        ui->batteryBar->setValue(255-doubles[3].toInt());
        ui->RSSIRcvDataLabel->setText((QString)doubles[5]);
        ui->SNRDataLabel->setText((QString)doubles[6]);

        if(doubles[2].toUShort() & (1<<3))
        {
            ui->parkingLabel->setText("OCCUPIED");
            ui->parkingLabel->setStyleSheet("QLabel { color : Red; }");
        }
        else
        {
            ui->parkingLabel->setText("FREE");
            ui->parkingLabel->setStyleSheet("QLabel { color : Green; }");
        }
        for (int i=0; i<ui->tableWidget->rowCount(); i++) {
            if ((ui->tableWidget->item(i,0)->text() != doubles[1])&&(ui->tableWidget->item(i,0)->text() ==" ")) {
                ui->tableWidget->setItem(i,0, new QTableWidgetItem((QString)doubles[1]));
                if(doubles[2].toUShort() & (1<<3))
                {
                    ui->tableWidget->setItem(i,1, new QTableWidgetItem("OCCUPIED"));
                }
                else
                {
                    ui->tableWidget->setItem(i,1, new QTableWidgetItem("FREE"));
                }
                //ui->tableWidget->setItem(i,2, new QTableWidgetItem((QString)doubles[3]));
                QProgressBar *table_bar = new QProgressBar();
                table_bar->setMaximum(130);
                table_bar->setValue(255-doubles[3].toInt());

                table_bar->setAlignment(Qt::AlignHCenter);
                ui->tableWidget->setCellWidget(i,2,table_bar);
                ui->tableWidget->setItem(i,3, new QTableWidgetItem((QString)doubles[5]));
                ui->tableWidget->setItem(i,4, new QTableWidgetItem((QString)doubles[6]));
                sens_num++;
                break;
            } else if (ui->tableWidget->item(i,0)->text() == doubles[1]){
                ui->tableWidget->setItem(i,0, new QTableWidgetItem((QString)doubles[1]));
                if(doubles[2].toUShort() & (1<<3))
                {
                    ui->tableWidget->setItem(i,1, new QTableWidgetItem("OCCUPIED"));
                }
                else
                {
                    ui->tableWidget->setItem(i,1, new QTableWidgetItem("FREE"));
                }
                //ui->tableWidget->setItem(i,2, new QTableWidgetItem((QString)doubles[3]));
                QProgressBar *table_bar2 = new QProgressBar();
                table_bar2->setMaximum(130);
                table_bar2->setValue(255-doubles[3].toInt());

                table_bar2->setAlignment(Qt::AlignHCenter);
                ui->tableWidget->setCellWidget(i,2,table_bar2);
                ui->tableWidget->setItem(i,3, new QTableWidgetItem((QString)doubles[5]));
                ui->tableWidget->setItem(i,4, new QTableWidgetItem((QString)doubles[6]));
                break;
               }
            }
         }
    } else {
        QTime current = QDateTime::currentDateTime().time();
        ui->consoleText->insertPlainText("["+current.toString()+"."+QString::number(current.msec())+"]: Packet error: "+data1);
        ui->consoleText->verticalScrollBar()->setValue(ui->consoleText->verticalScrollBar()->maximum());
    }
    data1.clear();
    serial->clear();
    done = false;
    }
    //serial->clear();
    //connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
}

//Function for read packets from Relay Switcher over Lora
void MainWindow::readRelayData()
{
    QFont font;
    font.setBold(true);
    if (!doneRelay){
    data2.append(serial->readAll());
    //ui->textEdit->insertPlainText(data2);
    if (data2.data()[data2.size()-1] == '\n') doneRelay=true;
    }
    //QByteArray data = serial->readLine(50);
    //disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    if (doneRelay){
    QList<QByteArray> doubles = data2.split(',');
    if (doubles.size()>6){
    if ((doubles[0].toInt()==ui->startByteEdit2->text().toInt(NULL, 16))&&(doubles[4].toInt()==ui->endByteEdit2->text().toInt(NULL, 16)))
    {
        //if (doubles[1]=="12345678") ui->textEdit->insertPlainText(doubles[1]);

        if(doubles[2].toInt() == 255)
        {
            ui->textEdit->insertPlainText("ACKOK: RELAY ON\r\n");
        }
        else
        {
            ui->textEdit->insertPlainText("ACKOK: RELAY OFF\r\n");
        }
        for (int i=0; i<ui->tableSensors->rowCount(); i++) {
            if ((ui->tableSensors->item(i,0)->text() != doubles[1])&&(ui->tableSensors->item(i,0)->text() ==" ")) {
                ui->tableSensors->setItem(i,0, new QTableWidgetItem((QString)doubles[1]));
                if(doubles[2].toInt() == 255)
                {

                    ui->tableSensors->setItem(i,1, new QTableWidgetItem("ON"));
                    ui->tableSensors->item(i,1)->setFont(font);
                    ui->tableSensors->item(i,1)->setForeground(QColor(Qt::darkGreen));//->setData(Qt::FontRole,QColor(Qt::green));

                }
                else
                {
                    ui->tableSensors->setItem(i,1, new QTableWidgetItem("OFF"));
                    ui->tableSensors->item(i,1)->setFont(font);
                    ui->tableSensors->item(i,1)->setForeground(QColor(Qt::red));

                }
                ui->tableSensors->setItem(i,2, new QTableWidgetItem("OK"));
                ui->tableSensors->item(i,2)->setFont(font);
                ui->tableSensors->item(i,2)->setForeground(QColor(Qt::darkGreen));

                ui->tableSensors->setItem(i,3, new QTableWidgetItem((QString)doubles[5]));
                ui->tableSensors->setItem(i,4, new QTableWidgetItem((QString)doubles[6]));
                sens_num2++;
                break;
            } else if (ui->tableSensors->item(i,0)->text() == doubles[1]){
                ui->tableSensors->setItem(i,0, new QTableWidgetItem((QString)doubles[1]));
                if(doubles[2].toInt() == 255)
                {
                    ui->tableSensors->setItem(i,1, new QTableWidgetItem("ON"));
                    ui->tableSensors->item(i,1)->setFont(font);
                    ui->tableSensors->item(i,1)->setForeground(QColor(Qt::darkGreen));//->setData(Qt::FontRole,QColor(Qt::green));
                }
                else
                {
                    ui->tableSensors->setItem(i,1, new QTableWidgetItem("OFF"));
                    ui->tableSensors->item(i,1)->setFont(font);
                    ui->tableSensors->item(i,1)->setForeground(QColor(Qt::red));
                }
                ui->tableSensors->setItem(i,2, new QTableWidgetItem("OK"));
                ui->tableSensors->item(i,2)->setFont(font);
                ui->tableSensors->item(i,2)->setForeground(QColor(Qt::darkGreen));
                ui->tableSensors->setItem(i,3, new QTableWidgetItem((QString)doubles[5]));
                ui->tableSensors->setItem(i,4, new QTableWidgetItem((QString)doubles[6]));
                break;
               }
            }
    }

    } else {
        ui->textEdit->insertPlainText("Packet error:");
        ui->textEdit->insertPlainText(data2);
        ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
    }
    data2.clear();
    serial->clear();
    doneRelay = false;
    }
    //serial->clear();
    //connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
}

//Function for read packets from TAG3 over Lora
void MainWindow::readGNSS()
{
    QByteArray data = serial->readAll();
    ui->gnssConsoleText->insertPlainText(data);
    ui->gnssConsoleText->verticalScrollBar()->setValue(ui->gnssConsoleText->verticalScrollBar()->maximum());
    if (data[0]=='V') {
        ui->gnssStatLabel->setStyleSheet("QLabel { color : Red; }");
        QList<QByteArray> doubles = data.split(',');
        if (!(doubles.size()<5)) {
            ui->timeLabel->setText((QString)doubles[1]);
            ui->rssiLabel->setText((QString)doubles[3]);
            ui->snrLabel->setText((QString)doubles[4]);
        }
    }

    if (data[0]=='A') {
        ui->gnssStatLabel->setStyleSheet("QLabel { color :Green; }");
        QList<QByteArray> doubles = data.split(',');
        if (!(doubles.size()<8)) {
            ui->timeLabel->setText((QString)doubles[1]);
            float ns = 1.0, ew = 1.0;
            if (doubles[4].at(0)=='N') ns = 1.0f; else ns=-1.0f;
            if (doubles[5].at(0)=='E') ew = 1.0f; else ew=-1.0f;
            float lat   = ns*Nmea2Dec(doubles[2].data(), 1);
            float longt = ew*Nmea2Dec(doubles[3].data(), 2);
            ui->latitudeLabel->setText(QString::number(lat, 'f', 6));
            ui->longtitudeLabel->setText(QString::number(longt, 'f', 6));
            ui->nsLabel->setText((QString)doubles[4]);
            ui->ewLabel->setText((QString)doubles[5]);
            ui->rssiLabel->setText((QString)doubles[6]);
            ui->snrLabel->setText((QString)doubles[7]);
            if (!(ui->checkBox->isChecked())) {
                QObject *rootObject = engine->rootObjects().first();
                QObject* mainMapCenter = rootObject->findChild<QObject*>("mainMap");
                if(mainMapCenter != NULL){
                    QVariant returnedValue;
                    QMetaObject::invokeMethod(mainMapCenter, "recenter",
                        Q_RETURN_ARG(QVariant, returnedValue),
                        Q_ARG(QVariant, QString::number(lat, 'f', 6).toFloat()), Q_ARG(QVariant, QString::number(longt, 'f', 6).toFloat()));
                }
            } else {
                QObject *rootObject = engine->rootObjects().first();
                QObject* mainMapCenter = rootObject->findChild<QObject*>("mainMap");
                if(mainMapCenter != NULL){
                    QVariant returnedValue;
                    QMetaObject::invokeMethod(mainMapCenter, "tracking",
                        Q_RETURN_ARG(QVariant, returnedValue),
                        Q_ARG(QVariant, QString::number(lat, 'f', 6).toFloat()), Q_ARG(QVariant, QString::number(longt, 'f', 6).toFloat()));
                }
            }
        }
    }
}

void MainWindow::readPATH(QByteArray data)
{
    ui->gnssConsoleText->insertPlainText((QString)data);
    if (data[0]=='A') {
        QList<QByteArray> doubles = data.split(',');
        if (!(doubles.size()<8)) {
            ui->timeLabel->setText(doubles[1]);
            float ns = 1.0, ew = 1.0;
            if (doubles[4].at(0)=='N') ns = 1.0f; else ns=-1.0f;
            if (doubles[5].at(0)=='E') ew = 1.0f; else ew=-1.0f;

            float lat   = ns*Nmea2Dec(doubles[2].data(), 1);//ns*doubles[2].toFloat()/100.00f;
            float longt = ew*Nmea2Dec(doubles[3].data(), 2);//ew*doubles[3].toFloat()/100.00f;
            QObject *rootObject = engine->rootObjects().first();
            QObject* mainMapCenter = rootObject->findChild<QObject*>("mainMap");
            if(mainMapCenter != NULL){
                QVariant returnedValue;
                QMetaObject::invokeMethod(mainMapCenter, "tracking",
                                        Q_RETURN_ARG(QVariant, returnedValue),
                                        Q_ARG(QVariant, QString::number(lat, 'f', 6).toFloat()),
                                        Q_ARG(QVariant, QString::number(longt, 'f', 6).toFloat()));
            }
        }
   }
}

unsigned short MainWindow::calculateCRC16(uint8_t input[], int lenght)
{
    unsigned short CRC16 = 0;
    for(int i = 0; i < lenght; i++)
    {
        unsigned  short tableValue = crc16table[((CRC16>>8)^*(char *)input++)&SHIFTER];
        CRC16=(CRC16<<8)^tableValue;
    }
    return CRC16;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    mode_flag = value;
    if (value==2) ui->tabWidget->setCurrentIndex(1);
    if (value==1) ui->tabWidget->setCurrentIndex(0);
    if (value==0) ui->tabWidget->setCurrentIndex(2);

    if (ui->ClosePort->isEnabled())
    {
        if (mode_flag==0) {
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::readRelayData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readGNSS);
        }
        if (mode_flag==1) {
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readRelayData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readGNSS);
        }
        if (mode_flag==2) {
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::readGNSS);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readRelayData);
            disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
        }
    }
}



void MainWindow::on_sendButton_clicked()
{
    serial->write(ui->commandEdit->text().toLocal8Bit());
}

void MainWindow::on_actionMap_VIewer_triggered()
{

}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Path Files (*.png)"));
    QObject *rootObject = engine->rootObjects().first();
    QObject* mainMapCenter = rootObject->findChild<QObject*>("mainMap");
    if(mainMapCenter != NULL){
        QVariant returnedValue;
        QMetaObject::invokeMethod(mainMapCenter, "savemap",
                                Q_RETURN_ARG(QVariant, returnedValue),
                                Q_ARG(QVariant, fileName));
    }

}

void MainWindow::on_pushButton_3_clicked()
{
     QString fileName = QFileDialog::getOpenFileName(this, tr("Open Path"), "", tr("Path Files (*.path *.txt)"));

     QFile inputFile(fileName);
     if (inputFile.open(QIODevice::ReadOnly))
     {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
           QString line = in.readLine()+"\r\n";
           //ui->gnssConsoleText->insertPlainText(line);
           readPATH(line.toUtf8());
        }
        inputFile.close();
     }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Log"), "", tr("Path Files (*.path)"));
    if (fileName != "") {
            QFile file(fileName);
            if (file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << ui->gnssConsoleText->toPlainText();
                file.flush();
                file.close();
            }
    }
}

float MainWindow::Nmea2Dec(char * nmea, char type)
{
    int idx, dot = 0;
    double dec = 0;
    for (idx=0; idx<strlen(nmea);idx++){
        if (nmea[idx] == '.'){
            dot = idx;
            break;
        }
    }

    if (dot < 3)
        return 0;

    int dd;
    double mm;
    char cdd[5], cmm[10];
    memset(&cdd, 0, 5);
    memset(&cmm, 0, 10);
    strncpy(cdd, nmea, dot-2);
    strcpy(cmm, nmea+dot-2);
    dd = atoi(cdd);
    mm = atof(cmm);

    dec = dd + (mm/60);

    if (type == 1 && dec > MAX_LATITUDE)
        return 0;
    else if (type == 2 && dec > MAX_LONGITUDE)
        return 0;

    return dec;
}

void MainWindow::on_pushButton_2_clicked()
{
    QObject *rootObject = engine->rootObjects().first();
    QObject* mainMapCenter = rootObject->findChild<QObject*>("mainMap");
    if(mainMapCenter != NULL){
        QVariant returnedValue;
        QMetaObject::invokeMethod(mainMapCenter, "clearmap",
                                Q_RETURN_ARG(QVariant, returnedValue));
    }
}

void MainWindow::on_zoomScrollBar_valueChanged(int value)
{
    QObject *rootObject = engine->rootObjects().first();
    QObject* mainMapCenter = rootObject->findChild<QObject*>("mainMap");
    if(mainMapCenter != NULL){
        QVariant returnedValue;
        QMetaObject::invokeMethod(mainMapCenter, "zoom",
                                Q_RETURN_ARG(QVariant, returnedValue),
                                Q_ARG(QVariant, ui->zoomScrollBar->value()));
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->gnssConsoleText->clear();
}


void MainWindow::on_pushButton_6_clicked()
{
    char send_cmd[13];
    char relay_state[2];
    if (ui->comboBox->currentIndex() == 0) {relay_state[0] = 'O'; relay_state[1] = 'N'; }
    if (ui->comboBox->currentIndex() == 1) {relay_state[0] = 'O'; relay_state[1] = 'F'; }
    sprintf(send_cmd,"%c%s%s%c\r\n", '#',ui->lineEdit_2->text().toLatin1().data(),relay_state,'@');
    serial->write(send_cmd);
}

void MainWindow::on_pushButton_SaveLog_clicked()
{
    QString nomeFile = QFileDialog::getSaveFileName(this, tr("Save log file"), "",
                                                        tr("File type (*.log);;Log File (*.log)"));
        if (nomeFile != "") {
            QFile file(nomeFile);

            if (file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << ui->consoleText->toPlainText();
                file.flush();
                file.close();
            }
            else {
                QMessageBox::critical(this, tr("Error"), tr("File doesn't exist"));
                return;
            }
        }
}

void MainWindow::on_pushButton_SaveLogTag3_clicked()
{
    QString nomeFile = QFileDialog::getSaveFileName(this, tr("Save log file"), "",
                                                        tr("File type (*.log);;Log File (*.log)"));
        if (nomeFile != "") {
            QFile file(nomeFile);

            if (file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << ui->gnssConsoleText->toPlainText();
                file.flush();
                file.close();
            }
            else {
                QMessageBox::critical(this, tr("Error"), tr("File doesn't exist"));
                return;
            }
        }
}

void MainWindow::on_pushButton_SaveLogSens_clicked()
{
    QString nomeFile = QFileDialog::getSaveFileName(this, tr("Save log file"), "",
                                                        tr("File type (*.log);;Log File (*.log)"));
        if (nomeFile != "") {
            QFile file(nomeFile);

            if (file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << ui->textEdit->toPlainText();
                file.flush();
                file.close();
            }
            else {
                QMessageBox::critical(this, tr("Error"), tr("File doesn't exist"));
                return;
            }
        }
}

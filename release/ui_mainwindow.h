/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMap_VIewer;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *serialPortComboBox;
    QLabel *portStatusLabel;
    QPushButton *OpenPort;
    QPushButton *ClosePort;
    QSpacerItem *horizontalSpacer_3;
    QSlider *horizontalSlider;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_17;
    QLabel *label_6;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *commandEdit;
    QPushButton *sendButton;
    QPlainTextEdit *consoleText;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_2;
    QLabel *parkingLabel;
    QLabel *label_5;
    QLabel *RSSIRcvDataLabel;
    QLabel *label_11;
    QLabel *SNRDataLabel;
    QLabel *label_3;
    QLabel *sensorAddressLabel;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLineEdit *startByteEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QLineEdit *endByteEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QLineEdit *ackByteEdit;
    QLabel *label_4;
    QLabel *batteryStatusLabel;
    QLabel *label_15;
    QProgressBar *batteryBar;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QScrollBar *zoomScrollBar;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_16;
    QLabel *snrLabel;
    QLabel *label_18;
    QLabel *rssiLabel;
    QLabel *gnssStatLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_19;
    QLabel *timeLabel;
    QLabel *label_20;
    QLabel *latitudeLabel;
    QLabel *label_21;
    QLabel *longtitudeLabel;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QLabel *nsLabel;
    QLabel *ewLabel;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QLabel *label_22;
    QPlainTextEdit *gnssConsoleText;
    QMenuBar *menuBar;
    QMenu *menuMain;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(808, 500);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(808, 500));
        MainWindow->setMaximumSize(QSize(1500, 1500));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionMap_VIewer = new QAction(MainWindow);
        actionMap_VIewer->setObjectName(QStringLiteral("actionMap_VIewer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        serialPortComboBox = new QComboBox(centralWidget);
        serialPortComboBox->setObjectName(QStringLiteral("serialPortComboBox"));

        horizontalLayout_2->addWidget(serialPortComboBox);

        portStatusLabel = new QLabel(centralWidget);
        portStatusLabel->setObjectName(QStringLiteral("portStatusLabel"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        portStatusLabel->setFont(font1);
        portStatusLabel->setStyleSheet(QStringLiteral("QLabel { color : Red; }"));

        horizontalLayout_2->addWidget(portStatusLabel);

        OpenPort = new QPushButton(centralWidget);
        OpenPort->setObjectName(QStringLiteral("OpenPort"));
        OpenPort->setEnabled(true);
        OpenPort->setFlat(false);

        horizontalLayout_2->addWidget(OpenPort);

        ClosePort = new QPushButton(centralWidget);
        ClosePort->setObjectName(QStringLiteral("ClosePort"));
        ClosePort->setEnabled(false);

        horizontalLayout_2->addWidget(ClosePort);

        horizontalSpacer_3 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QFont font2;
        font2.setPointSize(1);
        horizontalSlider->setFont(font2);
        horizontalSlider->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        horizontalSlider->setMaximum(2);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Vertical);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);

        horizontalLayout_2->addWidget(horizontalSlider);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_7->addWidget(label_17);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_7->addWidget(label_6);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_7->addWidget(label_7);


        horizontalLayout_2->addLayout(verticalLayout_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_8 = new QHBoxLayout(tab);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        commandEdit = new QLineEdit(tab);
        commandEdit->setObjectName(QStringLiteral("commandEdit"));
        commandEdit->setEnabled(false);

        horizontalLayout_4->addWidget(commandEdit);

        sendButton = new QPushButton(tab);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setEnabled(false);

        horizontalLayout_4->addWidget(sendButton);


        verticalLayout_8->addLayout(horizontalLayout_4);

        consoleText = new QPlainTextEdit(tab);
        consoleText->setObjectName(QStringLiteral("consoleText"));
        consoleText->setAutoFillBackground(false);
        consoleText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        consoleText->setReadOnly(true);
        consoleText->setCenterOnScroll(false);

        verticalLayout_8->addWidget(consoleText);

        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(5);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(20);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(15);

        verticalLayout_8->addWidget(tableWidget);


        horizontalLayout_8->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_9->addWidget(label_2);

        parkingLabel = new QLabel(tab);
        parkingLabel->setObjectName(QStringLiteral("parkingLabel"));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        parkingLabel->setFont(font3);
        parkingLabel->setTextFormat(Qt::AutoText);

        verticalLayout_9->addWidget(parkingLabel);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_9->addWidget(label_5);

        RSSIRcvDataLabel = new QLabel(tab);
        RSSIRcvDataLabel->setObjectName(QStringLiteral("RSSIRcvDataLabel"));
        QFont font4;
        font4.setPointSize(20);
        RSSIRcvDataLabel->setFont(font4);
        RSSIRcvDataLabel->setTextFormat(Qt::AutoText);

        verticalLayout_9->addWidget(RSSIRcvDataLabel);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_9->addWidget(label_11);

        SNRDataLabel = new QLabel(tab);
        SNRDataLabel->setObjectName(QStringLiteral("SNRDataLabel"));
        SNRDataLabel->setFont(font4);
        SNRDataLabel->setTextFormat(Qt::AutoText);

        verticalLayout_9->addWidget(SNRDataLabel);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_9->addWidget(label_3);

        sensorAddressLabel = new QLabel(tab);
        sensorAddressLabel->setObjectName(QStringLiteral("sensorAddressLabel"));
        sensorAddressLabel->setFont(font4);
        sensorAddressLabel->setTextFormat(Qt::AutoText);

        verticalLayout_9->addWidget(sensorAddressLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);


        horizontalLayout_8->addLayout(verticalLayout_9);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Raised);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_8->addWidget(line);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_5->addWidget(label_12);

        startByteEdit = new QLineEdit(tab);
        startByteEdit->setObjectName(QStringLiteral("startByteEdit"));
        startByteEdit->setEnabled(false);

        horizontalLayout_5->addWidget(startByteEdit);

        horizontalLayout_5->setStretch(0, 2);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_10->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_6->addWidget(label_13);

        endByteEdit = new QLineEdit(tab);
        endByteEdit->setObjectName(QStringLiteral("endByteEdit"));
        endByteEdit->setEnabled(false);

        horizontalLayout_6->addWidget(endByteEdit);

        horizontalLayout_6->setStretch(0, 10);
        horizontalLayout_6->setStretch(1, 5);

        verticalLayout_10->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_7->addWidget(label_14);

        ackByteEdit = new QLineEdit(tab);
        ackByteEdit->setObjectName(QStringLiteral("ackByteEdit"));
        ackByteEdit->setEnabled(false);

        horizontalLayout_7->addWidget(ackByteEdit);

        horizontalLayout_7->setStretch(0, 10);
        horizontalLayout_7->setStretch(1, 5);

        verticalLayout_10->addLayout(horizontalLayout_7);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_10->addWidget(label_4);

        batteryStatusLabel = new QLabel(tab);
        batteryStatusLabel->setObjectName(QStringLiteral("batteryStatusLabel"));
        batteryStatusLabel->setFont(font4);
        batteryStatusLabel->setTextFormat(Qt::AutoText);

        verticalLayout_10->addWidget(batteryStatusLabel);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_10->addWidget(label_15);

        batteryBar = new QProgressBar(tab);
        batteryBar->setObjectName(QStringLiteral("batteryBar"));
        batteryBar->setMaximum(100);
        batteryBar->setValue(0);
        batteryBar->setAlignment(Qt::AlignCenter);
        batteryBar->setInvertedAppearance(false);
        batteryBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_10->addWidget(batteryBar);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_3);


        horizontalLayout_8->addLayout(verticalLayout_10);

        horizontalLayout_8->setStretch(0, 50);
        horizontalLayout_8->setStretch(1, 10);
        horizontalLayout_8->setStretch(3, 10);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout_3->addLayout(verticalLayout);

        zoomScrollBar = new QScrollBar(tab_2);
        zoomScrollBar->setObjectName(QStringLiteral("zoomScrollBar"));
        zoomScrollBar->setMaximum(20);
        zoomScrollBar->setPageStep(1);
        zoomScrollBar->setValue(20);
        zoomScrollBar->setOrientation(Qt::Vertical);
        zoomScrollBar->setInvertedAppearance(true);

        horizontalLayout_3->addWidget(zoomScrollBar);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        label_16->setFont(font5);

        gridLayout->addWidget(label_16, 0, 0, 1, 1);

        snrLabel = new QLabel(tab_2);
        snrLabel->setObjectName(QStringLiteral("snrLabel"));
        QFont font6;
        font6.setPointSize(21);
        snrLabel->setFont(font6);

        gridLayout->addWidget(snrLabel, 1, 1, 1, 1);

        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font5);

        gridLayout->addWidget(label_18, 0, 1, 1, 1);

        rssiLabel = new QLabel(tab_2);
        rssiLabel->setObjectName(QStringLiteral("rssiLabel"));
        rssiLabel->setFont(font6);

        gridLayout->addWidget(rssiLabel, 1, 0, 1, 1);

        gnssStatLabel = new QLabel(tab_2);
        gnssStatLabel->setObjectName(QStringLiteral("gnssStatLabel"));
        QFont font7;
        font7.setPointSize(25);
        font7.setBold(true);
        font7.setWeight(75);
        gnssStatLabel->setFont(font7);

        gridLayout->addWidget(gnssStatLabel, 1, 2, 1, 1);

        gridLayout->setRowStretch(0, 5);
        gridLayout->setRowStretch(1, 95);
        gridLayout->setColumnStretch(0, 30);
        gridLayout->setColumnStretch(1, 30);
        gridLayout->setColumnStretch(2, 30);

        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font5);

        verticalLayout_2->addWidget(label_19);

        timeLabel = new QLabel(tab_2);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setFont(font6);
        timeLabel->setScaledContents(false);

        verticalLayout_2->addWidget(timeLabel);

        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font5);

        verticalLayout_2->addWidget(label_20);

        latitudeLabel = new QLabel(tab_2);
        latitudeLabel->setObjectName(QStringLiteral("latitudeLabel"));
        latitudeLabel->setFont(font6);

        verticalLayout_2->addWidget(latitudeLabel);

        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font5);

        verticalLayout_2->addWidget(label_21);

        longtitudeLabel = new QLabel(tab_2);
        longtitudeLabel->setObjectName(QStringLiteral("longtitudeLabel"));
        longtitudeLabel->setFont(font6);

        verticalLayout_2->addWidget(longtitudeLabel);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer);

        nsLabel = new QLabel(tab_2);
        nsLabel->setObjectName(QStringLiteral("nsLabel"));
        nsLabel->setFont(font6);

        verticalLayout_5->addWidget(nsLabel);

        ewLabel = new QLabel(tab_2);
        ewLabel->setObjectName(QStringLiteral("ewLabel"));
        ewLabel->setFont(font6);

        verticalLayout_5->addWidget(ewLabel);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_4->addWidget(checkBox);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_4->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_4->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_4->addWidget(pushButton_5);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);

        verticalLayout_4->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalLayout->setStretch(0, 30);

        verticalLayout_3->addLayout(horizontalLayout);

        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font5);

        verticalLayout_3->addWidget(label_22);

        gnssConsoleText = new QPlainTextEdit(tab_2);
        gnssConsoleText->setObjectName(QStringLiteral("gnssConsoleText"));
        gnssConsoleText->setReadOnly(true);
        gnssConsoleText->setBackgroundVisible(false);

        verticalLayout_3->addWidget(gnssConsoleText);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 10);
        verticalLayout_3->setStretch(2, 10);
        verticalLayout_3->setStretch(3, 90);

        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalLayout_3->setStretch(0, 70);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 25);
        tabWidget->addTab(tab_2, QString());

        verticalLayout_6->addWidget(tabWidget);

        verticalLayout_6->setStretch(0, 5);
        verticalLayout_6->setStretch(1, 100);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 808, 21));
        menuMain = new QMenu(menuBar);
        menuMain->setObjectName(QStringLiteral("menuMain"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy1);
        mainToolBar->setMaximumSize(QSize(1052, 685));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuMain->menuAction());
        menuMain->addAction(actionMap_VIewer);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Parking Server", Q_NULLPTR));
        actionMap_VIewer->setText(QApplication::translate("MainWindow", "Map VIewer", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "COM Port", Q_NULLPTR));
        portStatusLabel->setText(QApplication::translate("MainWindow", "Port Closed", Q_NULLPTR));
        OpenPort->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        ClosePort->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "GNSS (TAG3)", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Parking Sensor", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Service mode", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Command:", Q_NULLPTR));
        commandEdit->setText(QString());
        sendButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Parking Status:", Q_NULLPTR));
        parkingLabel->setText(QApplication::translate("MainWindow", "OCCUPIED", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "RSSI:", Q_NULLPTR));
        RSSIRcvDataLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "SNR:", Q_NULLPTR));
        SNRDataLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Sensor Address:", Q_NULLPTR));
        sensorAddressLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Start Byte", Q_NULLPTR));
        startByteEdit->setInputMask(QString());
        startByteEdit->setText(QApplication::translate("MainWindow", "A0", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Stop Byte", Q_NULLPTR));
        endByteEdit->setInputMask(QString());
        endByteEdit->setText(QApplication::translate("MainWindow", "B0", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "ACK", Q_NULLPTR));
        ackByteEdit->setInputMask(QString());
        ackByteEdit->setText(QApplication::translate("MainWindow", "C0", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Battery Status:", Q_NULLPTR));
        batteryStatusLabel->setText(QApplication::translate("MainWindow", "0x00", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Battery Level:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Parking Sensor", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "LoRa RSSI:", Q_NULLPTR));
        snrLabel->setText(QApplication::translate("MainWindow", "N/A", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "LoRa SNR:", Q_NULLPTR));
        rssiLabel->setText(QApplication::translate("MainWindow", "N/A", Q_NULLPTR));
        gnssStatLabel->setText(QApplication::translate("MainWindow", "GNSS", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "GNSS Time:", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("MainWindow", "N/A", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Latitude:", Q_NULLPTR));
        latitudeLabel->setText(QApplication::translate("MainWindow", "N/A", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Longtitude:", Q_NULLPTR));
        longtitudeLabel->setText(QApplication::translate("MainWindow", "N/A", Q_NULLPTR));
        nsLabel->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        ewLabel->setText(QApplication::translate("MainWindow", "E", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Tracking", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Clear map", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Open path", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Save log", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Clear log", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Save map", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Packet Log:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "GPS Map", Q_NULLPTR));
        menuMain->setTitle(QApplication::translate("MainWindow", "Main", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

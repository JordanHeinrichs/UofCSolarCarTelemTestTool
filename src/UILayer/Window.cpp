#include <iostream>
#include <QString>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QSerialPort>
#include <QLineEdit>
#include <QComboBox>
#include "Window.h"
#include "TelemetryReporting.h"
#include "SerialPortPeripheral.h"

Window::Window()
{
   setWindowTitle("Telem Test Program");
   setupUi();
   show();
}

Window::~Window()
{
}

void Window::setupUi()
{
   QWidget* mainWidget = new QWidget(this);
   QFormLayout* layout = new QFormLayout;

   connectButton_.reset(new QPushButton("&Connect", this));
   comPortLineEdit_.reset(new QLineEdit("/dev/ttyUSB0", this));
   connectionStatusLabel_.reset(new QLabel("Not connected", this));

   modeSelectionComboBox_.reset(new QComboBox());
   modeSelectionComboBox_->addItem("Random");
   modeSelectionComboBox_->addItem("Specified");

   sendKeyDriverControlButton_.reset(new QPushButton("Send Key Driver Control", this));
   QPushButton* keyDriverControlDetailsButton = new QPushButton("Details", this);

   sendDriverControlDetailsButton_.reset(new QPushButton("Send Driver Control Details", this));
   QPushButton* driverControlDetailsButton = new QPushButton("Details", this);

   sendFaultsButton_.reset(new QPushButton("Send Faults", this));
   QPushButton* faultsDetailsButton = new QPushButton("Details", this);

   sendBatteryDataButton_.reset(new QPushButton("Send Battery Data", this));
   QPushButton* batteryDataDetailsButton = new QPushButton("Details", this);

   sendCmuDataButton_.reset(new QPushButton("Send Cmu Data", this));
   QPushButton* cmuDataDetailsButton = new QPushButton("Details", this);

   sendMpptDataButton_.reset(new QPushButton("Send Mppt Data", this));
   QPushButton* mpptDataDetailsButton = new QPushButton("Details", this);

   sendAllButton_.reset(new QPushButton("Send All", this));

   layout->addRow(modeSelectionComboBox_.data(), connectButton_.data());
   layout->addRow(comPortLineEdit_.data());
   layout->addRow(connectionStatusLabel_.data());
   layout->addRow(keyDriverControlDetailsButton, sendKeyDriverControlButton_.data());
   layout->addRow(driverControlDetailsButton, sendDriverControlDetailsButton_.data());
   layout->addRow(faultsDetailsButton, sendFaultsButton_.data());
   layout->addRow(batteryDataDetailsButton, sendBatteryDataButton_.data());
   layout->addRow(cmuDataDetailsButton, sendCmuDataButton_.data());
   layout->addRow(mpptDataDetailsButton, sendMpptDataButton_.data());
   layout->addRow(sendAllButton_.data());
   mainWidget->setLayout(layout);
   setCentralWidget(mainWidget);
}

void Window::keyDriverControlDetails()
{
    QWidget* keyDriverControlDetailsWidget = new QWidget(this);
    QGridLayout* keyDriverControlLayout = new QGridLayout;

    QLabel* keyDriverSpeedLabel = new QLabel("Speed(rpm)", this);
    QLineEdit* keyDriverSpeedInput = new QLineEdit();
    QLabel* keyDriverCurrentLabel = new QLabel("Current(A)", this);
    QLineEdit* keyDriverCurrentInput = new QLineEdit();
    QLabel* keyDriverBusCurrentLabel = new QLabel("Bus Current(A)", this);
    QLineEdit* keyDriverBusCurrentInput = new QLineEdit();
    QLabel* keyDriverVoltageLabel = new QLabel("Bus Voltage(V)", this);
    QLineEdit* keyDriverVoltageInput = new QLineEdit();
    QLabel* keyDriverVelocityLabel = new QLabel("Current(A)", this);
    QLineEdit* keyDriverVelocityInput = new QLineEdit();

    QPushButton* keyDriverControlDoneButton = new QPushButton("Done", this);
    connect(keyDriverControlDoneButton, SIGNAL(clicked()), keyDriverControlDetailsWidget, SLOT(close()));


    keyDriverControlLayout->addWidget(keyDriverSpeedLabel,0,0);
    keyDriverControlLayout->addWidget(keyDriverSpeedInput,0,1);
    keyDriverControlLayout->addWidget(keyDriverCurrentLabel,1,0);
    keyDriverControlLayout->addWidget(keyDriverCurrentInput,1,1);
    keyDriverControlLayout->addWidget(keyDriverBusCurrentLabel,2,0);
    keyDriverControlLayout->addWidget(keyDriverBusCurrentInput,2,1);
    keyDriverControlLayout->addWidget(keyDriverVoltageLabel,3,0);
    keyDriverControlLayout->addWidget(keyDriverVoltageInput,3,1);
    keyDriverControlLayout->addWidget(keyDriverVelocityLabel,4,0);
    keyDriverControlLayout->addWidget(keyDriverVelocityInput,4,1);
    keyDriverControlLayout->addWidget(keyDriverControlDoneButton,5,0);

    keyDriverControlDetailsWidget->setLayout(keyDriverControlLayout);
    keyDriverControlDetailsWidget->setWindowFlags(Qt::Window);
    keyDriverControlDetailsWidget->show();
}

void Window::driverControlDetails()
{
    QWidget* driverControlDetailsWidget = new QWidget(this);
    QGridLayout* driverControlLayout = new QGridLayout;

    QLabel* driverMotorVelocityLabel = new QLabel("Motor Velocity(rpm)", this);
    QLineEdit* driverMotorVelocityInput = new QLineEdit();
    QLabel* driverMotorVoltageLabel = new QLabel("Motor Voltage(V)", this);
    QLineEdit* driverMotorVoltageInput = new QLineEdit();
    QLabel* driverMotorCurrentLabel = new QLabel("Motor Current(A)", this);
    QLineEdit* driverMotorCurrentInput = new QLineEdit();
    QLabel* driverEMFImaginaryLabel = new QLabel("Back EMF Imaginary", this);
    QLineEdit* driverEMFImaginaryInput = new QLineEdit();
    QLabel* driverDSPBoardLabel = new QLabel("DSP Board Temp", this);
    QLineEdit* driverDSPBoardInput = new QLineEdit();
    QLabel* driverDcBusLabel = new QLabel("DC Bus(AmpHours)", this);
    QLineEdit* driverDcBusInput = new QLineEdit();
    QLabel* driverOdometerLabel = new QLabel("Odometer", this);
    QLineEdit* driverOdometerInput = new QLineEdit();

    QPushButton* driverControlDoneButton = new QPushButton("Done", this);
    connect(driverControlDoneButton, SIGNAL(clicked()), driverControlDetailsWidget, SLOT(close()));

    driverControlLayout->addWidget(driverMotorVelocityLabel,0,0);
    driverControlLayout->addWidget(driverMotorVelocityInput,0,1);
    driverControlLayout->addWidget(driverMotorVoltageLabel,1,0);
    driverControlLayout->addWidget(driverMotorVoltageInput,1,1);
    driverControlLayout->addWidget(driverMotorCurrentLabel,2,0);
    driverControlLayout->addWidget(driverMotorCurrentInput,2,1);
    driverControlLayout->addWidget(driverEMFImaginaryLabel,3,0);
    driverControlLayout->addWidget(driverEMFImaginaryInput,3,1);
    driverControlLayout->addWidget(driverDSPBoardLabel,4,0);
    driverControlLayout->addWidget(driverDSPBoardInput,4,1);
    driverControlLayout->addWidget(driverDcBusLabel,5,0);
    driverControlLayout->addWidget(driverDcBusInput,5,1);
    driverControlLayout->addWidget(driverOdometerLabel,6,0);
    driverControlLayout->addWidget(driverOdometerInput,6,1);
    driverControlLayout->addWidget(driverControlDoneButton,7,0);

    driverControlDetailsWidget->setLayout(driverControlLayout);
    driverControlDetailsWidget->setWindowFlags(Qt::Window);
    driverControlDetailsWidget->show();
}

QPushButton& Window::getConnectButton()
{
    return *connectButton_;
}

QLineEdit& Window::getComPortLineEdit()
{
    return *comPortLineEdit_;
}

QLabel& Window::getConnectionStatusLabel()
{
    return *connectionStatusLabel_;
}

QString& Window::getTestingMode()
{
    return *testingMode_;
}

QComboBox& Window::getModeSelectionComboBox()
{
    return *modeSelectionComboBox_;
}

QPushButton& Window::getSendKeyDriverControlButton()
{
    return *sendKeyDriverControlButton_;
}

QPushButton& Window::getSendDriverControlDetailsButton()
{
    return *sendDriverControlDetailsButton_;
}

QPushButton& Window::getSendFaultsButton()
{
    return *sendFaultsButton_;
}

QPushButton& Window::getSendBatteryDataButton()
{
    return *sendBatteryDataButton_;
}

QPushButton& Window::getSendCmuDataButton()
{
    return *sendCmuDataButton_;
}

QPushButton& Window::getSendMpptDataButton()
{
    return *sendMpptDataButton_;
}

QPushButton& Window::getSendAllButton()
{
    return *sendAllButton_;
}

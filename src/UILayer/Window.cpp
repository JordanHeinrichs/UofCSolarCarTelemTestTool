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

   layout->addRow(connectButton_.data());
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

QPushButton& Window::getSendKeyDriverControlButton()
{
    return *sendKeyDriverControlButton_;
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

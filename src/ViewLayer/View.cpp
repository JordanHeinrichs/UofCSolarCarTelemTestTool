#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include "View.h"
#include "Window.h"
#include "WindowDesign.h"

namespace
{
   const int BAUDRATE = 9600;
   const int NUMBER_OF_CMUS = 4;
   const int NUMBER_OF_MPPTS = 7;
}

View::View()
{
    window_ = new Window();
    connectToUi();
    setUpWindowDesign();
}

void View::setUpWindowDesign()
{
    new WindowDesign();
}

void View::connectToUi()
{
    window_->connect(&(window_->getConnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptConnectionSignal()));
    window_->connect(&(window_->getSendKeyDriverControlButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendKeyDriverControlSignal()));
    window_->connect(&(window_->getSendFaultsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendFaultsSignal()));
    window_->connect(&(window_->getSendBatteryDataButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendBatteryDataSignal()));
    window_->connect(&(window_->getSendCmuDataButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendCmuDataSignal()));
    window_->connect(&(window_->getSendMpptDataButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendMpptDataSignal()));
    window_->connect(&(window_->getSendAllButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendAllSignal()));
}

void View::setConnectionStatus(bool connectionStatus)
{
    if(connectionStatus)
    {
        window_->getConnectionStatusLabel().setText("Connected.");
    }
    else
    {
        window_->getConnectionStatusLabel().setText("Connection Failed.");
    }
}

QString View::getCommunicationPort()
{
    return window_->getComPortLineEdit().text();
}

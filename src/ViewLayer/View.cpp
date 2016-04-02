#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include "View.h"
#include "Window.h"

namespace
{
   const int BAUDRATE = 9600;
   const int NUMBER_OF_CMUS = 4;
   const int NUMBER_OF_MPPTS = 7;
}

View::View(Window& window)
: window_(window)
{
    connectToUi();
}

void View::connectToUi()
{
    window_.connect(&(window_.getConnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptConnectionSignal()));
    window_.connect(&(window_.getModeSelectionComboBox()), SIGNAL(editTextChanged(QString)),
                     this, SIGNAL(differentModeSelectedSignal()));
    window_.connect(&(window_.getSendKeyDriverControlButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendKeyDriverControlSignal()));
    window_.connect(&(window_.getSendDriverControlDetailsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendDriverControlDetailsSignal()));
    window_.connect(&(window_.getSendFaultsButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendFaultsSignal()));
    window_.connect(&(window_.getSendBatteryDataButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendBatteryDataSignal()));
    window_.connect(&(window_.getSendCmuDataButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendCmuDataSignal()));
    window_.connect(&(window_.getSendMpptDataButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendMpptDataSignal()));
    window_.connect(&(window_.getSendAllButton()), SIGNAL(clicked()),
                     this, SIGNAL(sendAllSignal()));
}

void View::setConnectionStatus(bool connectionStatus)
{
    if(connectionStatus)
    {
        window_.getConnectionStatusLabel().setText("Connected.");
    }
    else
    {
        window_.getConnectionStatusLabel().setText("Connection Failed.");
    }
}

QString View::getModeSelected()
{
    return window_.getModeSelectionComboBox().currentText();
}

QString View::getCommunicationPort()
{
    return window_.getComPortLineEdit().text();
}

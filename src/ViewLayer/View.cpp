#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QComboBox>
#include "View.h"
#include "Window.h"

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
}

void View::connectToUi()
{
    window_->connect(&(window_->getConnectButton()), SIGNAL(clicked()),
                     this, SIGNAL(attemptConnectionSignal()));
    window_->connect(&(window_->getSendButton()), SIGNAL(clicked()),
                     this, SLOT(emitSendSignals()));
    window_->connect(&(window_->getKeyDriverControlsSubmitButton()), SIGNAL(clicked()),
                     this, SLOT(changeKeyDriverControlsData()));
}

void View::emitSendSignals()
{
    if(window_->getSendKeyDriverControlCheckBox().isChecked())
    {
        emit sendKeyDriverControlSignal();
    }
    if(window_->getSendDriverControlDetailsCheckBox().isChecked())
    {
        emit sendDriverControlDetailsSignal();
    }
    if(window_->getSendFaultsCheckBox().isChecked())
    {
        emit sendFaultsSignal();
    }
    if(window_->getSendBatteryDataCheckBox().isChecked())
    {
        emit sendBatteryDataSignal();
    }
    if(window_->getSendCmuDataCheckBox().isChecked())
    {
        emit sendCmuDataSignal();
    }
    if(window_->getSendMpptDataCheckBox().isChecked())
    {
        emit sendMpptDataSignal();
    }
}

void View::changeKeyDriverControlsData()
{
    float driverSetSpeed = (float) window_->getDriverSetSpeedRpmSpinBox().value();
    float driverSetCurrent = (float) window_->getDriverSetCurrentSpinBox().value();
    float vehicleVelocity = (float) window_->getVehicleVelocitySpinBox().value();
    float busCurrent = (float) window_->getBusCurrentSpinBox().value();
    float busVoltage = (float) window_->getBusVoltageSpinBox().value();

    emit changeKeyDriverControlsSignal(driverSetSpeed,
                                       driverSetCurrent,
                                       vehicleVelocity,
                                       busCurrent,
                                       busVoltage);
}

void View::setConnectionStatus(bool connectionStatus)
{
    if(connectionStatus)
    {
        window_->getConnectionStatusLabel().setText("Connected");
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

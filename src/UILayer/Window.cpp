#include <QString>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QSerialPort>
#include <QLineEdit>
#include <QComboBox>
#include <QScopedPointer>
#include "Window.h"
#include "ui_WindowDesign.h"

Window::Window()
: ui(new Ui::WindowDesign)
{
    ui->setupUi(this);
    this->setWindowTitle("Telem Test Program");
    this->show();
}

Window::~Window()
{
    delete ui;
}

QPushButton& Window::getConnectButton()
{
    return *ui->connectButton;
}

QPushButton& Window::getSendButton()
{
    return *ui->sendButton;
}

QPushButton& Window::getKeyDriverControlsSubmitButton()
{
    return *ui->keyDriverControlsSubmitButton;
}

QLineEdit& Window::getComPortLineEdit()
{
    return *ui->comPortLineEdit;
}

QLabel& Window::getConnectionStatusLabel()
{
    return *ui->displayConnectionStatusLabel;
}

QCheckBox& Window::getSendKeyDriverControlCheckBox()
{
    return *ui->sendKeyDriverControlCheckBox;
}

QCheckBox& Window::getSendDriverControlDetailsCheckBox()
{
    return *ui->sendDriverControlDetailsCheckBox;
}

QCheckBox& Window::getSendFaultsCheckBox()
{
    return *ui->sendFaultsCheckBox;
}

QCheckBox& Window::getSendBatteryDataCheckBox()
{
    return *ui->sendBatteryDataCheckBox;
}

QCheckBox& Window::getSendCmuDataCheckBox()
{
    return *ui->sendCmuDataCheckBox;
}

QCheckBox& Window::getSendMpptDataCheckBox()
{
    return *ui->sendMpptDataCheckBox;
}

QDoubleSpinBox& Window::getDriverSetSpeedRpmSpinBox()
{
    return *ui->driverSetSpeedRpmSpinBox;
}

QDoubleSpinBox& Window::getDriverSetCurrentSpinBox()
{
    return *ui->driverSetCurrentSpinBox;
}

QDoubleSpinBox& Window::getVehicleVelocitySpinBox()
{
    return *ui->vehicleVelocitySpinBox;
}

QDoubleSpinBox& Window::getBusCurrentSpinBox()
{
    return *ui->busCurrentSpinBox;
}

QDoubleSpinBox& Window::getBusVoltageSpinBox()
{
    return *ui->busVoltageSpinBox;
}

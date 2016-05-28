#include "WindowDesign.h"
#include "ui_WindowDesign.h"

WindowDesign::WindowDesign()
: ui(new Ui::WindowDesign)
{
    this->setWindowTitle("Telem Test Program");
    ui->setupUi(this);
    this->show();
}

WindowDesign::~WindowDesign()
{
    delete ui;
}

QPushButton& WindowDesign::getConnectButton()
{
    return *ui->connectButton;
}

QLineEdit& WindowDesign::getComPortLineEdit()
{
    return *ui->comPortLineEdit;
}

QLabel& WindowDesign::getConnectionStatusLabel()
{
    return *ui->displayConnectionStatusLabel;
}

QCheckBox& WindowDesign::getSendKeyDriverControlCheckBox()
{
    return *ui->sendKeyDriverControlCheckBox;
}

QCheckBox& WindowDesign::getSendFaultsCheckBox()
{
    return *ui->sendFaultsCheckBox;
}

QCheckBox& WindowDesign::getSendBatteryDataCheckBox()
{
    return *ui->sendBatteryDataCheckBox;
}

QCheckBox& WindowDesign::getSendCmuDataCheckBox()
{
    return *ui->sendCmuDataCheckBox;
}

QCheckBox& WindowDesign::getSendMpptDataCheckBox()
{
    return *ui->sendMpptDataCheckBox;
}

#pragma once

//#include <QMainWindow>
//#include <QWidget>
#include <QTabWidget>

class QPushButton;
class QComboBox;
class QLineEdit;
class QDoubleSpinBox;
class QLabel;
class QCheckBox;

namespace Ui{
    class WindowDesign;
}

class Window : public QTabWidget
{
    Q_OBJECT
public:
    explicit Window();
    ~Window();
    //Change to QScopedPointers later
    QPushButton& getConnectButton();
    QPushButton& getSendButton();
    QPushButton& getKeyDriverControlsSubmitButton();
    QLineEdit& getComPortLineEdit();
    QLabel& getConnectionStatusLabel();
    QCheckBox& getSendKeyDriverControlCheckBox();
    QCheckBox& getSendDriverControlDetailsCheckBox();
    QCheckBox& getSendFaultsCheckBox();
    QCheckBox& getSendBatteryDataCheckBox();
    QCheckBox& getSendCmuDataCheckBox();
    QCheckBox& getSendMpptDataCheckBox();
    QDoubleSpinBox& getDriverSetSpeedRpmSpinBox();
    QDoubleSpinBox& getDriverSetCurrentSpinBox();
    QDoubleSpinBox& getVehicleVelocitySpinBox();
    QDoubleSpinBox& getBusCurrentSpinBox();
    QDoubleSpinBox& getBusVoltageSpinBox();


private:
    Ui::WindowDesign *ui;
};


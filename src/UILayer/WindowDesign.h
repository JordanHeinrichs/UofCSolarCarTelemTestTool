#pragma once

//#include <QMainWindow>
//#include <QWidget>
#include <QTabWidget>
class QPushButton;
class QComboBox;
class QLineEdit;
class QLabel;
class QCheckBox;

namespace Ui{
    class WindowDesign;
}

class WindowDesign : public QTabWidget
{
    Q_OBJECT
public:
    explicit WindowDesign();
    ~WindowDesign();
    QPushButton& getConnectButton();
    QLineEdit& getComPortLineEdit();
    QLabel& getConnectionStatusLabel();
    QCheckBox& getSendKeyDriverControlCheckBox();
    QCheckBox& getSendFaultsCheckBox();
    QCheckBox& getSendBatteryDataCheckBox();
    QCheckBox& getSendCmuDataCheckBox();
    QCheckBox& getSendMpptDataCheckBox();

private:
    Ui::WindowDesign *ui;
};


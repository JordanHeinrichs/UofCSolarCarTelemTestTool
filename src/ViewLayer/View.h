#ifndef VIEW_H
#define VIEW_H

#include <QObject>
class QSerialPort;
class Window;
class QPushButton;
class QComboBox;
class QLineEdit;
class QDoubleSpinBox;
class QLabel;
class QCheckBox;

class View : public QObject
{
    Q_OBJECT
public:
    View();
    void setConnectionStatus(bool connectionStatus);
    QString getCommunicationPort();
    QString getModeSelected();

private:
    void connectToUi();

private slots:
    void emitSendSignals();
    void changeKeyDriverControlsData();

signals:
    void attemptConnectionSignal();
    void sendKeyDriverControlSignal();
    void sendDriverControlDetailsSignal();
    void sendFaultsSignal();
    void sendBatteryDataSignal();
    void sendCmuDataSignal();
    void sendMpptDataSignal();
    //void changeDataSignal(); //remove later
    void changeKeyDriverControlsSignal(float driverSetSpeed,
                                       float driverSetCurrent,
                                       float vehicleVelocity,
                                       float busCurrent,
                                       float busVoltage);

    //useless/to-be-removed
    void differentModeSelectedSignal();
    void sendAllSignal();
    void changeDataSignal();


private:
    Window* window_;
};

#endif // VIEW_H

#ifndef VIEW_H
#define VIEW_H

#include <QObject>
class QSerialPort;
class Window;
class WindowDesign;
class QPushButton;
class QComboBox;
class QLineEdit;
class QLabel;

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
    void connectTest();
    void setUpWindowDesign();

signals:
    void attemptConnectionSignal();
    void differentModeSelectedSignal();
    void sendKeyDriverControlSignal();
    void sendDriverControlDetailsSignal();
    void sendFaultsSignal();
    void sendBatteryDataSignal();
    void sendCmuDataSignal();
    void sendMpptDataSignal();
    void sendAllSignal();
    void changeDataSignal();


private:
    Window* window_;
};

#endif // VIEW_H

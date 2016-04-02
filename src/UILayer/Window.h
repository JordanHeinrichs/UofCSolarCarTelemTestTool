#pragma once

#include <QMainWindow>
class QPushButton;
class QComboBox;
class QLineEdit;
class QLabel;
class TelemetryReporting;
class View;

class Window : public QMainWindow
{
   Q_OBJECT
public:
   Window();
   virtual ~Window();

public:
   QPushButton& getConnectButton();
   QLineEdit& getComPortLineEdit();
   QLabel& getConnectionStatusLabel();
   QString& getTestingMode();
   QComboBox& getModeSelectionComboBox();
   QPushButton& getSendKeyDriverControlButton();
   QPushButton& getSendDriverControlDetailsButton();
   QPushButton& getSendFaultsButton();
   QPushButton& getSendBatteryDataButton();
   QPushButton& getSendCmuDataButton();
   QPushButton& getSendMpptDataButton();
   QPushButton& getSendAllButton();
   void setConnectionStatusText(QString);

   //void getConnectionStatus

private:
   void setupUi();
   void connectPointers();
   void keyDriverControlDetails();
   void driverControlDetails();

private:
   QScopedPointer<QPushButton> connectButton_;
   QScopedPointer<QLineEdit> comPortLineEdit_;
   QScopedPointer<QLabel> connectionStatusLabel_;
   QScopedPointer<QString> testingMode_;
   QScopedPointer<QComboBox> modeSelectionComboBox_;
   QScopedPointer<QPushButton> sendKeyDriverControlButton_;
   QScopedPointer<QPushButton> sendDriverControlDetailsButton_;
   QScopedPointer<QPushButton> sendFaultsButton_;
   QScopedPointer<QPushButton> sendBatteryDataButton_;
   QScopedPointer<QPushButton> sendCmuDataButton_;
   QScopedPointer<QPushButton> sendMpptDataButton_;
   QScopedPointer<QPushButton> sendAllButton_;
};

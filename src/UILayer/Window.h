#pragma once

#include <QMainWindow>
class QPushButton;
class QComboBox;
class QLineEdit;
class QLabel;

class Window : public QMainWindow
{
   Q_OBJECT
public:
   Window();
   virtual ~Window();

public:
   QPushButton& getConnectButton();
   QLineEdit& getComPortLineEdit();
   QString& getTestingMode();
   QComboBox& getModeSelectionComboBox();
   QLabel& getConnectionStatusLabel();
   QPushButton& getSendKeyDriverControlButton();
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

private:
   QScopedPointer<QPushButton> connectButton_;
   QScopedPointer<QLineEdit> comPortLineEdit_;
   QScopedPointer<QLabel> connectionStatusLabel_;
   QScopedPointer<QString> testingMode_;
   QScopedPointer<QPushButton> sendKeyDriverControlButton_;
   QScopedPointer<QPushButton> sendDriverControlDetailsButton_;
   QScopedPointer<QPushButton> sendFaultsButton_;
   QScopedPointer<QPushButton> sendBatteryDataButton_;
   QScopedPointer<QPushButton> sendCmuDataButton_;
   QScopedPointer<QPushButton> sendMpptDataButton_;
   QScopedPointer<QPushButton> sendAllButton_;
};

#pragma once

#include <QApplication>
#include <QScopedPointer>
#include <QSerialPort>
#include "TelemetryReporting.h"
#include "VehicleData.h"
#include "View.h"
#include "Window.h"
#include "SerialPortPeripheral.h"

class TestApplication : public QApplication
{
   Q_OBJECT
public:
   TestApplication(int& argc, char** argv);
   virtual ~TestApplication();

private:
   QScopedPointer<QSerialPort> serialPort_;
   QScopedPointer<SerialPortPeripheral> serialPortPeripheral_;
   QScopedPointer<VehicleData> vehicleData_;
   QScopedPointer<Window> window_;
   QScopedPointer<View> view_;
   QScopedPointer<TelemetryReporting> telemetryReporting_;
};

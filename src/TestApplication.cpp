#include "TestApplication.h"

TestApplication::TestApplication(int& argc, char** argv)
: QApplication(argc, argv)
, serialPort_(new QSerialPort())
, serialPortPeripheral_(new SerialPortPeripheral(*serialPort_))
, vehicleData_(new VehicleData())
, window_(new Window())
, view_(new View(*window_))
, telemetryReporting_(new TelemetryReporting(*serialPort_, *serialPortPeripheral_, *vehicleData_, *view_))
{
}
    TestApplication::~TestApplication()
{
}

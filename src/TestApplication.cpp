#include "TestApplication.h"

TestApplication::TestApplication(int& argc, char** argv)
: QApplication(argc, argv)
, serialPort_(new QSerialPort())
, serialPortPeripheral_(new SerialPortPeripheral(*serialPort_))
, vehicleData_(new VehicleData())
, view_(new View())
, telemetryReporting_(new TelemetryReporting(*serialPortPeripheral_, *vehicleData_, *view_))
{
}
    TestApplication::~TestApplication()
{
}

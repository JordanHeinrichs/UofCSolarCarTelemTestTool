#include "TestApplication.h"

TestApplication::TestApplication(int& argc, char** argv)
: QApplication(argc, argv)
, vehicleData_(new VehicleData())
, view_(new View())
, communicationService_(new CommunicationService(*view_))
, telemetryReporting_(new TelemetryReporting(*communicationService_, *vehicleData_, *view_))
{
}

TestApplication::~TestApplication()
{
}

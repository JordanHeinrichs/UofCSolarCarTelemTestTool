#pragma once

#include <QApplication>
#include <QScopedPointer>
#include "TelemetryReporting.h"
#include "VehicleData.h"
#include "View.h"
#include "CommunicationService.h"

class TestApplication : public QApplication
{
   Q_OBJECT
public:
   TestApplication(int& argc, char** argv);
   virtual ~TestApplication();

private:
   QScopedPointer<VehicleData> vehicleData_;
   QScopedPointer<View> view_;
   QScopedPointer<CommunicationService> communicationService_;
   QScopedPointer<TelemetryReporting> telemetryReporting_;
};

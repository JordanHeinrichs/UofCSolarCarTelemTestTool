#include "DataModifier.h"
#include "View.h"
#include "VehicleData.h"

/*  This class is a WIP, still unsure about what the data in VehicleData will end up
 *  looking like so for now it's just set up to connect properly between the
 *  View and the Data
 */
DataModifier::DataModifier(VehicleData& vehicleData, View& view)
: vehicleData_(vehicleData)
,view_(view)
{
    connectToView();
}

void DataModifier::changeData()
{
    //thinking of having a method for each tab from the UI
    //vehicleData_.busCurrent = 5.0f;
}

void DataModifier::changeKeyDriverControls(float driverSetSpeed, float driverSetCurrent, float vehicleVelocity, float busCurrent, float busVoltage)
{
    //cout << "ahi" << endl; //TODO, doesn't seem to be connected. No compilation errors though
    vehicleData_.driverSetSpeedRpm = driverSetSpeed;
    vehicleData_.driverSetCurrent = driverSetCurrent;
    vehicleData_.vehicleVelocity = vehicleVelocity;
    vehicleData_.busCurrent = busCurrent;
    vehicleData_.busVoltage = busVoltage;
}

void DataModifier::connectToView()
{
    connect(&view_, SIGNAL(changeDataSignal()), this, SLOT(changeData()));
    connect(&view_, SIGNAL(changeKeyDriverControlsSignal(float driverSetSpeed,
                                                         float driverSetCurrent,
                                                         float vehicleVelocity,
                                                         float busCurrent,
                                                         float busVoltage)),
            this, SLOT(changeKeyDriverControls(float driverSetSpeed,
                                               float driverSetCurrent,
                                               float vehicleVelocity,
                                               float busCurrent,
                                               float busVoltage)));
}

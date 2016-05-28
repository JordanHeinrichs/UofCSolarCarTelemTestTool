#include "DataModifier.h"
#include "View.h"
#include "VehicleData.h"

/*  This class is a WIP, still unsure about what the data in VehicleData will end up
 *  looking like so for now it's just set up to connect properly between the
 *  View and the Data
 */
DataModifier::DataModifier(View& view, VehicleData& vehicleData)
:view_(view)
,vehicleData_(vehicleData)
{
    connectToView();
}

void DataModifier::changeData()
{
    //thinking of having a method for each tab from the UI
    //vehicleData_.busCurrent = 5.0f;
}

void DataModifier::connectToView()
{
    connect(&view_, SIGNAL(changeDataSignal()), this, SLOT(changeData()));
}

#ifndef DATAMODIFIER_H
#define DATAMODIFIER_H

#include <QObject>
class View;
class VehicleData;

class DataModifier : public QObject
{
public:
    DataModifier(VehicleData& vehicleData, View& view);

private:
    void changeData();
    void changeKeyDriverControls(float driverSetSpeed,
                            float driverSetCurrent,
                            float vehicleVelocity,
                            float busCurrent,
                            float busVoltage);
    void connectToView();

private:
    VehicleData& vehicleData_;
    View& view_;
};

#endif // DATAMODIFIER_H

#ifndef DATAMODIFIER_H
#define DATAMODIFIER_H

#include <QObject>
class View;
class VehicleData;

class DataModifier : public QObject
{
public:
    DataModifier(View& view, VehicleData& vehicleData);

private:
    void connectToView();
    void changeData();

private:
    View& view_;
    VehicleData& vehicleData_;
};

#endif // DATAMODIFIER_H

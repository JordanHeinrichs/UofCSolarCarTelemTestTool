#pragma once
/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2015 by University of Calgary Solar Car Team
-------------------------------------------------------*/
#include <QObject>
class QDebug;
class QIODevice;
class VehicleData;
class SerialPortPeripheral;
class QSerialPort;
class View;
class Window;

class TelemetryReporting : public QObject
{
    Q_OBJECT
public:
   TelemetryReporting(QIODevice& device,
                      SerialPortPeripheral& peripheral,
                      VehicleData& vehicleData,
                      View& view);

private slots:
   void attemptConnection();
   void differentModeSelected();
   void sendKeyDriverControlTelemetry();
   void sendDriverControlDetails();
   void sendFaults();
   void sendBatteryData();
   void sendCmuData();
   void sendMpptData();
   void sendAll();

private:
   // Will return length of framed data
   unsigned int frameData(const unsigned char* dataToEncode,
         unsigned long length, unsigned char* frameData);
   // Will return length of encoded data
   unsigned int stuffData(const unsigned char* dataToEncode,
         unsigned long length, unsigned char* encodedData);
   // Add checksum into data at index length and length + 1
   void addChecksum(unsigned char* data, unsigned int length);

   void writeFloatIntoData(unsigned char* data, int index, const float& value);
   void sendData(const unsigned char* data, int length);
   void connectToView();
   void sendCmu(unsigned char cmuDataIndex);
   void sendMppt(unsigned char mpptDataIndex);

private:
   QIODevice& outputDevice_;
   SerialPortPeripheral& serialPortPeripheral_;
   VehicleData& vehicleData_;
   View& view_;
};

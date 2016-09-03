#pragma once

#include "I_CommPeripheral.h"

class QStringList;
class QSerialPort;

class SerialPortPeripheral : public I_CommPeripheral
{
public:
    SerialPortPeripheral(QSerialPort& serialPort);
    virtual ~SerialPortPeripheral();
    bool attemptConnection();
    //Sets the port name to parameters[0]
    void setParameters(QStringList parameters);
    void sendData(const unsigned char* data, int length);

private:
    QSerialPort& serialPort_;
};

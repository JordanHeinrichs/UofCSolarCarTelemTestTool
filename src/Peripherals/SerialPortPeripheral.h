#pragma once
class QString;
class QSerialPort;

/*
 *
 */
class SerialPortPeripheral
{
public:
    SerialPortPeripheral(QSerialPort& serialPort);
    bool attemptConnection();
    void setPortName(QString portName);
private:
    QSerialPort& serialPort_;
};

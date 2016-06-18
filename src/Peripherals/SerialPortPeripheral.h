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
    void sendData(const unsigned char* data, int length);
private:
    QSerialPort& serialPort_;
};

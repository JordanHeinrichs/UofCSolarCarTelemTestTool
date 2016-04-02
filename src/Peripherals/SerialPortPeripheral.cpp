#include "SerialPortPeripheral.h"
#include <QSerialPort>
#include <QString>

/*
 *
 */
namespace
{
    const int BAUDRATE = 9600;
    const int NUMBER_OF_CMUS = 4;
    const int NUMBER_OF_MPPTS = 7;
}
SerialPortPeripheral::SerialPortPeripheral(QSerialPort& serialPort)
: serialPort_(serialPort)
{
    serialPort_.setBaudRate(BAUDRATE);
}

void SerialPortPeripheral::setPortName(QString portName)
{
    serialPort_.setPortName(portName);
}

bool SerialPortPeripheral::attemptConnection()
{
   if (serialPort_.open(QIODevice::ReadWrite))
   {
      return true;
   }
   else
   {
      return false;
   }
}

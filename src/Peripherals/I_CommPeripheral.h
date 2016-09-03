#pragma once

class QStringList;

class I_CommPeripheral
{
public:
    virtual bool attemptConnection() = 0;
    virtual void setParameters(QStringList parameters) = 0;
    virtual void sendData(const unsigned char* data, int length) = 0;
    virtual ~I_CommPeripheral(){}
};

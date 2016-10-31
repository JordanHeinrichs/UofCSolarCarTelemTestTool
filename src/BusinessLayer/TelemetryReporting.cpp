/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2015 by University of Calgary Solar Car Team
-------------------------------------------------------*/

#include <QIODevice>
#include <CcsDefines.h>
#include <CrcCalculator.h>
#include <TelemetryReporting.h>
#include <VehicleData.h>
#include <CommunicationService.h>
#include <View.h>

union FloatDataUnion
{
   float floatData;
   char charData[4];
};

namespace
{
   // These lengths only include the data. Not the checksum
   const unsigned int KEY_DRIVER_CONTROL_LENGTH = 21;
   const unsigned int DRIVER_CONTROL_DETAILS_LENGTH = 29;
   const unsigned int FAULT_LENGTH = 9;
   const unsigned int BATTERY_DATA_LENGTH = 18;
   const unsigned int CMU_DATA_LENGTH = 42;
   const unsigned int MPPT_DATA_LENGTH = 21;
   const unsigned int CHECKSUM_LENGTH = 2;

   const unsigned int FRAMING_LENGTH_INCREASE = 5;
   const unsigned char TERMINATING_BYTE = 0x00;

   // Packet IDs
   const unsigned char KEY_DRIVER_CONTROL_ID = 0x01;
   const unsigned char DRIVER_CONTROL_DETAILS_ID = 0x02;
   const unsigned char FAULT_ID = 0x03;
   const unsigned char BATTERY_DATA_ID = 0x04;
   const unsigned char CMU_DATA_ID = 0x05;
   const unsigned char MPPT_DATA_ID = 0x06;

   const int NUMBER_OF_CMUS = 4;
   const int NUMBER_OF_MPPTS = 7;
}

TelemetryReporting::TelemetryReporting(CommunicationService& commService,
                                       VehicleData& vehicleData,
                                       View& view)
: communicationService_(commService)
, vehicleData_(vehicleData)
, view_(view)
{
    //Connect slots to View Signals
    connect(&view_, SIGNAL(sendKeyDriverControlSignal()), this, SLOT(sendKeyDriverControlTelemetry()));
    connect(&view_, SIGNAL(sendDriverControlDetailsSignal()), this, SLOT(sendDriverControlDetails()));
    connect(&view_, SIGNAL(sendFaultsSignal()), this, SLOT(sendFaults()));
    connect(&view_, SIGNAL(sendBatteryDataSignal()), this, SLOT(sendBatteryData()));
    connect(&view_, SIGNAL(sendCmuDataSignal()), this, SLOT(sendCmuData()));
    connect(&view_, SIGNAL(sendMpptDataSignal()), this, SLOT(sendMpptData()));
    connect(&view_, SIGNAL(sendAllSignal()), this, SLOT(sendAll()));
    //Might need to connect a signal for whenever the serial port gets updated to a slot
    //that updates the outputDevice_ to the updated device.
}

void TelemetryReporting::sendKeyDriverControlTelemetry()
{
   const unsigned int unframedPacketLength = KEY_DRIVER_CONTROL_LENGTH + CHECKSUM_LENGTH;
   unsigned char packetPayload[unframedPacketLength];
   packetPayload[0] = KEY_DRIVER_CONTROL_ID;
   const float driverSetSpeedMps = vehicleData_.driverSetSpeedRpm * CcsDefines::RPM_TO_MPS_CONVERSION;
   writeFloatIntoArray(packetPayload, 1, driverSetSpeedMps);
   writeFloatIntoArray(packetPayload, 5, vehicleData_.driverSetCurrent);
   writeFloatIntoArray(packetPayload, 9, vehicleData_.busCurrent);
   writeFloatIntoArray(packetPayload, 13, vehicleData_.busVoltage);
   writeFloatIntoArray(packetPayload, 17, vehicleData_.vehicleVelocity);

   addChecksum(packetPayload, KEY_DRIVER_CONTROL_LENGTH);
   unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
   unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
   communicationService_.sendData(packet, packetLength);
}

void TelemetryReporting::sendDriverControlDetails()
{
   const unsigned int unframedPacketLength = DRIVER_CONTROL_DETAILS_LENGTH + CHECKSUM_LENGTH;
   unsigned char packetPayload[unframedPacketLength];
   packetPayload[0] = DRIVER_CONTROL_DETAILS_ID;
   writeFloatIntoArray(packetPayload, 1, vehicleData_.motorVelocityRpm);
   writeFloatIntoArray(packetPayload, 5, vehicleData_.motorVoltageReal);
   writeFloatIntoArray(packetPayload, 9, vehicleData_.motorCurrentReal);
   writeFloatIntoArray(packetPayload, 13, vehicleData_.backEmfImaginary);
   writeFloatIntoArray(packetPayload, 17, vehicleData_.dspBoardTemp);
   writeFloatIntoArray(packetPayload, 21, vehicleData_.dcBusAmpHours);
   writeFloatIntoArray(packetPayload, 25, vehicleData_.odometer);

   addChecksum(packetPayload, DRIVER_CONTROL_DETAILS_LENGTH);
   unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
   unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
   communicationService_.sendData(packet, packetLength);
}

void TelemetryReporting::sendFaults()
{
   const unsigned int unframedPacketLength = FAULT_LENGTH + CHECKSUM_LENGTH;
   unsigned char packetPayload[unframedPacketLength];
   packetPayload[0] = FAULT_ID;
   packetPayload[1] = static_cast<unsigned char>(0xFF & vehicleData_.motorOneErrorFlags);
   packetPayload[2] = static_cast<unsigned char>(0xFF & vehicleData_.motorOneLimitFlags);
   packetPayload[3] = static_cast<unsigned char>(0xFF & vehicleData_.motorTwoErrorFlags);
   packetPayload[4] = static_cast<unsigned char>(0xFF & vehicleData_.motorTwoLimitFlags);
   packetPayload[5] = static_cast<unsigned char>(0xFF & vehicleData_.bmuStatusFlagsExtended);
   packetPayload[6] = static_cast<unsigned char>(0xFF & (vehicleData_.bmuStatusFlagsExtended >> 8));
   packetPayload[7] = vehicleData_.motorOneReceivedErrorCount;
   packetPayload[8] = vehicleData_.motorOneTransmittedErrorCount;

   addChecksum(packetPayload, FAULT_LENGTH);
   unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
   unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
   communicationService_.sendData(packet, packetLength);
}

void TelemetryReporting::sendBatteryData()
{
   const unsigned int unframedPacketLength = BATTERY_DATA_LENGTH + CHECKSUM_LENGTH;
   unsigned char packetPayload[unframedPacketLength];
   packetPayload[0] = BATTERY_DATA_ID;
   writeFloatIntoArray(packetPayload, 1, vehicleData_.batteryVoltage);
   writeFloatIntoArray(packetPayload, 5, vehicleData_.batteryCurrent);
   writeFloatIntoArray(packetPayload, 9, vehicleData_.packStateOfChargePercentage);
   writeFloatIntoArray(packetPayload, 13, vehicleData_.balancePackStateOfCharge);
   packetPayload[17] = static_cast<unsigned char>(vehicleData_.secondaryBatteryUnderVoltage);

   addChecksum(packetPayload, BATTERY_DATA_LENGTH);
   unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
   unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
   communicationService_.sendData(packet, packetLength);
}

void TelemetryReporting::sendCmuData()
{
    for (int cmuDataIndex = 0; cmuDataIndex < NUMBER_OF_CMUS; ++cmuDataIndex)
    {
        const unsigned int unframedPacketLength = CMU_DATA_LENGTH + CHECKSUM_LENGTH;
        unsigned char packetPayload[unframedPacketLength];
        packetPayload[0] = CMU_DATA_ID;
        packetPayload[1] = cmuDataIndex;
        writeFloatIntoArray(packetPayload, 2, vehicleData_.cmuData[cmuDataIndex].pcbTemperature);
        writeFloatIntoArray(packetPayload, 6, vehicleData_.cmuData[cmuDataIndex].cellTemperature);
        writeFloatIntoArray(packetPayload, 10, vehicleData_.cmuData[cmuDataIndex].cellVoltage[0]);
        writeFloatIntoArray(packetPayload, 14, vehicleData_.cmuData[cmuDataIndex].cellVoltage[1]);
        writeFloatIntoArray(packetPayload, 18, vehicleData_.cmuData[cmuDataIndex].cellVoltage[2]);
        writeFloatIntoArray(packetPayload, 22, vehicleData_.cmuData[cmuDataIndex].cellVoltage[3]);
        writeFloatIntoArray(packetPayload, 26, vehicleData_.cmuData[cmuDataIndex].cellVoltage[4]);
        writeFloatIntoArray(packetPayload, 30, vehicleData_.cmuData[cmuDataIndex].cellVoltage[5]);
        writeFloatIntoArray(packetPayload, 34, vehicleData_.cmuData[cmuDataIndex].cellVoltage[6]);
        writeFloatIntoArray(packetPayload, 38, vehicleData_.cmuData[cmuDataIndex].cellVoltage[7]);

        addChecksum(packetPayload, CMU_DATA_LENGTH);
        unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
        unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
        communicationService_.sendData(packet, packetLength);
    }
}

void TelemetryReporting::sendMpptData()
{
    for (int mpptDataIndex = 0; mpptDataIndex < NUMBER_OF_MPPTS; ++mpptDataIndex)
    {
        const unsigned int unframedPacketLength = MPPT_DATA_LENGTH + CHECKSUM_LENGTH;
        unsigned char packetPayload[unframedPacketLength];
        packetPayload[0] = MPPT_DATA_ID;
        packetPayload[1] = mpptDataIndex;
        packetPayload[2] = static_cast<unsigned char>(vehicleData_.mpptData[mpptDataIndex].type);

        if (vehicleData_.mpptData[mpptDataIndex].type == MpptData::Helianthus)
        {
           packetPayload[3] = 0x1F;
        }
        else
        {
           packetPayload[3] = 0x07;
        }
        writeFloatIntoArray(packetPayload, 4, vehicleData_.mpptData[mpptDataIndex].voltageIn);
        writeFloatIntoArray(packetPayload, 8, vehicleData_.mpptData[mpptDataIndex].currentIn);
        writeFloatIntoArray(packetPayload, 12, vehicleData_.mpptData[mpptDataIndex].voltageOut);
        writeFloatIntoArray(packetPayload, 16, vehicleData_.mpptData[mpptDataIndex].currentOut);
        packetPayload[20] = static_cast<unsigned char>(vehicleData_.mpptData[mpptDataIndex].mode);

        addChecksum(packetPayload, MPPT_DATA_LENGTH);
        unsigned char packet[unframedPacketLength + FRAMING_LENGTH_INCREASE];
        unsigned int packetLength = frameData(packetPayload, unframedPacketLength, packet);
        communicationService_.sendData(packet, packetLength);
    }
}

void TelemetryReporting::sendAll()
{
    sendKeyDriverControlTelemetry();
    sendDriverControlDetails();
    sendFaults();
    sendBatteryData();
    sendCmuData();
    sendMpptData();
}

unsigned int TelemetryReporting::frameData(const unsigned char* dataToEncode,
      unsigned long length, unsigned char* frameData)
{
   unsigned int lengthOfFramedData =
      stuffData(dataToEncode, length, frameData);
   frameData[lengthOfFramedData++] = TERMINATING_BYTE;
   return lengthOfFramedData;
}

#define FINISH_BLOCK(X) \
{\
   *code_ptr = (X); \
   code_ptr = encodedData++; \
   code = 0x01; \
}

unsigned int TelemetryReporting::stuffData(const unsigned char* dataToEncode,
      unsigned long length, unsigned char* encodedData)
{
   unsigned int lengthOfEncodedData = length + 1;
   const unsigned char* end = dataToEncode + length;
   unsigned char* code_ptr = encodedData++;
   unsigned char code = 0x01;

   while (dataToEncode < end)
   {
      if (*dataToEncode == 0)
      {
         FINISH_BLOCK(code);
      }
      else
      {
         *encodedData++ = *dataToEncode;
         code++;
         if (code == 0xFF)
         {
            FINISH_BLOCK(code);
            lengthOfEncodedData++;
         }
      }
      dataToEncode++;
   }
   FINISH_BLOCK(code);
   return lengthOfEncodedData;
}
#undef FINISH_BLOCK

void TelemetryReporting::addChecksum(unsigned char* data, unsigned int length)
{
   unsigned short crc16 = CrcCalculator::calculateCrc16(data, length);
   data[length] = static_cast<unsigned char>(0xFF & crc16);
   data[length + 1] = static_cast<unsigned char>(0xFF & (crc16 >> 8));
}

void TelemetryReporting::writeFloatIntoArray(unsigned char* data, int index, const float& value)
{
   FloatDataUnion floatDataUnion;
   floatDataUnion.floatData = value;
   data[index++] = floatDataUnion.charData[0];
   data[index++] = floatDataUnion.charData[1];
   data[index++] = floatDataUnion.charData[2];
   data[index] = floatDataUnion.charData[3];
}

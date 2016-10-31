/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2014 by University of Calgary Solar Car Team
-------------------------------------------------------*/

#include <CmuData.h>

CmuData::CmuData()
{
   static int cmuCount = 0;

   pcbTemperature = 46 + (cmuCount * 10);
   cellTemperature = 47 + (cmuCount * 10);

   for(int i = 0; i < 8; i++)
   {
      cellVoltage[i] = i + 48 + (cmuCount * 10);
   }

   cmuCount++;
}

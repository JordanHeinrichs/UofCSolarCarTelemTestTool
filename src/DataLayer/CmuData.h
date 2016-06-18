#pragma once
/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2014 by University of Calgary Solar Car Team
-------------------------------------------------------*/

struct CmuData
{
   CmuData();

   float pcbTemperature;
   float cellTemperature;
   float cellVoltage[8];
};

/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2014 by University of Calgary Solar Car Team
-------------------------------------------------------*/

#include <MpptData.h>

int MpptData::mpptCount = 0;

MpptData::MpptData()
: type(Helianthus)
, mode(Static)
, voltageIn(126.0f + mpptCount * 4)
, voltageOut(127.0f + mpptCount * 4)
, currentIn(128.0f + mpptCount * 4)
, currentOut(129.0f + mpptCount * 4)
{
   ++mpptCount;
}

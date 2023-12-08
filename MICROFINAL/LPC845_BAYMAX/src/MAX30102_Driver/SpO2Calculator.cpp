#include "Defines.h"

uint8_t update(uint32_t irACValue,uint32_t redACValue)
{


	uint32_t irACValueSqSum;
	uint32_t redACValueSqSum;


	uint8_t spO2;

	uint8_t spO2LUT[43] = {100,100,100,100,99,99,99,99,99,99,98,98,98,98,
	                                             98,97,97,97,97,97,97,96,96,96,96,96,96,95,95,
	                                             95,95,95,95,94,94,94,94,94,93,93,93,93,93};
    irACValueSqSum += irACValue * irACValue;
    redACValueSqSum += redACValue * redACValue;

	uint32_t acSqRatio = 100.0 * log(redACValueSqSum) / log(irACValueSqSum);
	uint32_t index = 0;

	if (acSqRatio > 66) {
		index = (uint32_t)acSqRatio - 66;
	} else if (acSqRatio > 50) {
		index = (uint32_t)acSqRatio - 50;
	}

    redACValueSqSum = 0;
    irACValueSqSum = 0;

    spO2 = 0;
    if(index <= 43 )
    {
    	spO2 = spO2LUT[index];
    }
    else
    {
    	spO2=0;
    }


	return spO2;
}



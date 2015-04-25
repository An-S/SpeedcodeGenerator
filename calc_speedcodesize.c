#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#include "speedcode_Internal.h"

spcode_Size_t spcode_CalcSize(register spcode_Spec_t* spdcdef)
{
	spcode_Size_t spcodesize=0;
	spcode_Iterator_t i=0;

	for (; i<spdcdef->Limits.Part; i++)
	{
		spcodesize += spdcdef->PartSpec[i].Size * spdcdef->PartSpec[i].Repeats;
	}
	//Sum up size contribution of speedcode parts with respect to partrepeat

	return spcodesize*spdcdef->Limits.x*
											spdcdef->Limits.y*
											spdcdef->Limits.z +1;
	//Multiply contribution of parts with number of repeats in x,y,z
	//and add 1 for rts
}

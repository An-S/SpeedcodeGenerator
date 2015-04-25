#ifndef __SPDC_H
#define __SPDC_H

#define RTS 0x60

/* 18.1.2013 In union spcodecounters wurde index[] in arr[] umbenannt und counters in index, damit 
	diese Union mit der struct spcode konsistent ist */

#include <stdlib.h>
#include <stdint.h>

#include "opcodes_incl_illegals.h" //Definitions for 6502 opcodes
#include "speedcode_macros.h"
#include "speedcode_ExternalTypes.h"





//************ 
//Use these function prototypes directly
spcode_t* __fastcall__ spcode_Create(spcode_Spec_t *spcode_Def, spcode_t *Dest);
spcode_Size_t spcode_CalcSize(register spcode_Spec_t* spdcdef);
void spcode_Add (void* source, size_t size);
spcode_Iterator_t __fastcall__ spcode_GetCounter(uint8_t counterindex);
//************

/*struct _spdcdef_and_counters
{
	spcode_counters counters;
	spcode_spec spdcdef_loc;
};*/
//Don't use!

//extern struct _spdcdef_and_counters spdcdef_and_counters;
//Don't use!

//#define spcode_counter spdcdef_and_counters.counters

#endif
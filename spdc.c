#include <string.h>
#include "speedcode.h"
#include <stddef.h>
#include <stdbool.h>

void __fastcall__ create_speedcode(register spcode_Spec_t *spdcdef, void(*dest)(void), void(*func)(unsigned int reppos) ){
	unsigned int i=0;
	static void* saveadr;

	if(NULL != dest){saveadr=dest;}

	for(;i<(spdcdef->Limits.x);i++){
		if(NULL != func){func(i);}
		memcpy((unsigned char*)saveadr, spdcdef->PartSpec, spdcdef->PartSpec->Size);
		(unsigned char*)saveadr+=spdcdef->PartSpec->Size;
	}
	if(NULL != dest) {*(unsigned char*)saveadr=RTS;}
}

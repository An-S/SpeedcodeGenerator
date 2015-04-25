#include "speedcode.h"
#include "speedcode_Internal.h"
#include <stddef.h>

extern spcode_SpecAndState_t spcode_def_loc;
extern spcode_PartSpec_t spdcpartdef_loc;

spcode_Iterator_t __fastcall__ spcode_GetCounter(uint8_t /*counterindex*/)
{
	//asm("ldy #%o",counterindex);
	//asm("lda (sp),y");

	//if (counterindex < PARTREPEATCOUNT_IDX)
	//{
		asm("asl");
		asm("tax");
		asm("lda %v+%b,x", spcode_def_loc, offsetof(spcode_SpecAndState_t, Limits));
		asm("sec");
		asm("sbc %v+%b,x",spcode_def_loc, offsetof(spcode_SpecAndState_t, Counters));
		asm("pha");
		asm("lda %v+%b+1,x", spcode_def_loc, offsetof(spcode_SpecAndState_t, Limits));
		asm("sbc %v+%b+1,x", spcode_def_loc, offsetof(spcode_SpecAndState_t, Counters));
		asm("tax");
		asm("pla");
		return __AX__;
	//}
	//else
	//{
	//return spdcpartdef_loc.repeatcount-spcode_def_loc.counters.partrepeat;
	//}
	//return spcode_def_loc.repeat.arr[counterindex]-spcode_def_loc.counters.arr[counterindex];
	//Invert counter as loops run from max downto zero and not the otherway round
}

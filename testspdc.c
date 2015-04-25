#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <conio.h>

#include <stdlib.h>

#include <stddef.h>
#include <stdbool.h>
#include <time.h>

#include "speedcode.h"
#include "speedcode_Internal.h"
#include "testspdc.h"

//Minimum clock cycles for 2000 lda stas: 260;( , 251

//spcode_counters counters;

spcodepart_parameters spar = {(uint8_t*)0x401, (uint8_t*)0x400};

uint8_t testcode[] = {1,2,3,4,5,6,7,8,9,10};



void waitkey(void)
{
	printf("\nPress key!\n");
	while( !kbhit() );
	cgetc();
}

void modspcode(register void* par){
	typedef spcodepart_parameters* p;
	
	testspcode.src = ((p)par)->srcstartadr + spcode_GetCounter(SPCODE_PARTREPEAT_IDX);
	testspcode.dest = ((p)par)->deststartadr + spcode_GetCounter(SPCODE_PARTREPEAT_IDX);
}

//****************************************************************************************
//Tests the speecode generator routine "spcode_CopyPart"
//****************************************************************************************
int TestSpeedcodeCopyPartFunc(void)
{
	spcode_t *spcodeadr;
	static spcode_PartSpec_t spcodepart[] = 
	{
		{
			&testcode,
			sizeof(testcode),
			2,
			NULL,
			NULL
		}
	};

	spcodeadr = malloc( sizeof(testcode)*spcodepart[0].Repeats );
	printf("Testing function \"spcode_CopyPart\"...\n" "Dest Addr = %x\n", spcodeadr);
	waitkey();
	
	spcodeadr == spcode_SetDestination( spcodeadr );
	assert ( spcodeadr == spcode_SetDestination( spcodeadr ) );
	//Assert that destination is set correctly. 
	//In debug version, the address is assigned two times, but this does not affect the result
	
	spcode_CopyPart( &spcodepart[0] );
	assert ( 0 == memcmp (spcodeadr, testcode, sizeof(testcode)) );
	//assert that the copy of testcode is the same as testcode
	assert ( 0 == memcmp ((unsigned char*)spcodeadr + sizeof(testcode), testcode, sizeof(testcode)) );
	//assert that the second copy of testcode is the same as testcode
	free(spcodeadr);
	
	printf("Successful call to function \"spcode_CopyPart\"...\n");
	waitkey();	
	
	return EXIT_SUCCESS;
}

//****************************************************************************************
//Tests the speecode generator routine "spcode_Create"
//****************************************************************************************
int TestSpeedcodeCreateFunc(void)
{
	spcode_t *spcodeadr; 
	clock_t clock_temp;
	spcode_Size_t spcodesize;
	
	static spcode_PartSpec_t spcodepartdef[] = 
	{
		{
			&testspcode,
			(size_t)&spcodelen,
			2000,
			modspcode,
			&spar
		}
	};
		
	static spcode_Spec_t spcodedef = {
		{{1,
		1,
		1,
		sizeof(spcodepartdef)/sizeof(spcodepartdef[0])}},
		spcodepartdef
	};

	extern unsigned int srcadr,destadr;
	
	spcodesize = spcode_CalcSize(&spcodedef);
	spcodeadr = malloc(spcodesize);
	
	printf("Adress of spcode %x\n"
				 "Speedcode modification routine %x\n"
				 "Length of spcode %d\n"
				 "Total number of repeats %d\n"
				 "Destination Adr %x\n"
				 "Required memory %x\n", 	spcodedef.PartSpec[0].AssemblyCode, 
				 													spcodedef.PartSpec[0].Callback,
				 													spcodedef.PartSpec[0].Size,
																	spcodedef.Limits.x*spcodedef.Limits.y*spcodedef.Limits.z*
																	spcodedef.PartSpec[0].Repeats, 
																	spcodeadr, spcodesize);
	
	waitkey();
																	
	clock_temp = clock();
	spcodeadr = spcode_Create(&spcodedef, spcodeadr); 
	clock_temp = clock() - clock_temp;
	
	printf("Clocks needed for setup:%lu", clock_temp);
	free(spcodeadr);
	waitkey();
	
	return EXIT_SUCCESS;
}

int main(void)
{	

	TestSpeedcodeCopyPartFunc();
	TestSpeedcodeCreateFunc();
	
	
	
	/*while(true){
		spcodeadr();
		*(unsigned char*)(0x0427) = i++;
	}*/
	
	
	return 0;
}

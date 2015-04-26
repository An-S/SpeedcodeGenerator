#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>

#include "speedcode.h"
#include "speedcode_Internal.h"
#include <mem\mem.h>

/*CC65 Bug: &nameofstruct != nameofstruct
						void (*dest)(void), ++dest increases dest by 2 instead of one!*/

/* Smallest Size: 0x1bd, 0x1ba, 0x1c1*/

//#define spcode_def_loc spdcdef_and_counters.spdcdef_loc

//spcode_spec spcode_def_loc;


spcode_SpecAndState_t spcode_def_loc;
spcode_PartSpec_t spdcpartdef_loc;
//The memory seems to be allocated wrongly

//ptrdiff_t counter_offset;
// Offset between storage area of maxima and counters

static spcode_t *spcode_StoreDest;



spcode_t* __fastcall__ spcode_SetDestination(spcode_t *dest)
{
	spcode_StoreDest = dest;
	return spcode_StoreDest;
}

//***********************************************************************************
//Replicate the small piece of assembler code and modify the code after each copy
//***********************************************************************************
void __fastcall__ spcode_CopyPart(register spcode_PartSpec_t *spcode_partdef)
{
	//void (*callback(unsigned int*)) = spcode_partdef->callback;
    static uint8_t rts = 0x60;

	dprintf("-- Called \"spcode_CopyPart\", &Partspec=%x --\n", spcode_partdef);

    //Optimization could be to copy only necessary information like pointer to assembly and size
    //Use local pointer var i instead of spcode_def_loc.Counters.PartRepeat
	COPY_SPEEDCODEPART_SPEC(*spcode_partdef, spdcpartdef_loc);
	if(NULL == spdcpartdef_loc.Callback){spdcpartdef_loc.Callback = (void*)&rts;}

	//assert( 0 == memcmp ( spcode_partdef, &spdcpartdef_loc, sizeof(spcode_PartSpec_t) ) );
	//Assert that the struct spcode_partdef is correctly copied to the local representation

	spcode_def_loc.Counters.PartRepeat = spcode_def_loc.Limits.PartRepeat = spdcpartdef_loc.Repeats;
	assert ( 0 == spcode_GetCounter(SPCODE_PARTREPEAT_IDX) );
	//GetCounter must return zero for the startvalue of the counter

    for( ;spcode_def_loc.Counters.PartRepeat > 0; --spcode_def_loc.Counters.PartRepeat )
        /*To avoid side effects using this loop function with recursive functions, the comparison and the incrementation are not
            bundled together in one command*/
    {
        dprintf("  Iteration:%d, Counter:%d\n", spcode_def_loc.Counters.PartRepeat-1, spcode_GetCounter(SPCODE_PARTREPEAT_IDX));
        //if(spdcpartdef_loc.callback){spdcpartdef_loc.callback(spdcpartdef_loc.parameters);}
        //(unsigned char*)storedest = (unsigned char*)memcpy(storedest, spdcpartdef_loc.assembly_code, spdcpartdef_loc.size)+spdcpartdef_loc.size;
        //copycode();
        //dprintf("  Partrepeatcount: %d\n", spcode_def_loc.repeat.part);

        //Secure, because pointer to rts is written if function pointer is NULL
        spdcpartdef_loc.Callback(spdcpartdef_loc.Parameters);
        //(unsigned char*)spcode_StoreDest = (unsigned char*)memcpy256(spdcpartdef_loc.Size, spdcpartdef_loc.AssemblyCode, spcode_StoreDest);
        (unsigned char*)spcode_StoreDest = (unsigned char*)fastmemcpy256(spdcpartdef_loc.Size, spdcpartdef_loc.AssemblyCode, spcode_StoreDest);
        //spcode_Add (spdcpartdef_loc.AssemblyCode, spdcpartdef_loc.Size);
        //Inner Loop Counter works ok, if spcode_Add is not called. Something interferes!
    }
}

//***********************************************************************************
//Add a small piece of assembler code to the generated speedcode
//***********************************************************************************
void spcode_Add (void* source, size_t size)
{
	(unsigned char*)spcode_StoreDest = (unsigned char*)fastmemcpy256(size, source, spcode_StoreDest);
	assert ( 0 == memcmp (source, (unsigned char*)spcode_StoreDest-size, size) );
	//Assert that copying was successful

	//(unsigned char*)memcpy(storedest, source, size) + size;
}

//***********************************************************************************
//Run the loops for the replication and call routine for copying the assembly code
//***********************************************************************************
void __fastcall__ spcode_Replicate(register spcode_Iterator_t *indexarr)
{
	//register unsigned int *indexarr = index;
		//The partindex of the indexarray must be specified


	//Maximum and running values have constant offset in structure. so calculate pointer to max value
	//from pointer to running value
	spcode_Iterator_t *max = (spcode_Iterator_t*)(
												(uint8_t*)indexarr -
												( offsetof(spcode_SpecAndState_t, Counters) -
												  offsetof(spcode_SpecAndState_t, Limits) )
											);

    //Output debug information about the call and the recursion level
	dprintf("## Called \"create_loop\" with level:%d ##\n",
				(max-(spcode_Iterator_t*)&spcode_def_loc.Limits)
			 );

	if ( indexarr <= &spcode_def_loc.Counters.Part )
	{
		//unsigned int max_loc = *max;

		// no NULL Pointer acceptable, pointer not outside reserved memspace
		assert( max >= (spcode_Iterator_t*)(&spcode_def_loc.Limits) );
		assert( max <= (spcode_Iterator_t*)(&spcode_def_loc.Limits + 1) );

		// no NULL Pointer acceptable, pointer not outside reserved memspace
		assert( indexarr >= &spcode_def_loc.Counters.arr[0] );
		assert( indexarr <= ( &spcode_def_loc.Counters.arr[SPCODE_NUMOFLOOPS-1] ) );

		dprintf("Max:%d, &Max:%x, &Last Index:%x, \n", *max, max, &spcode_def_loc.Limits.Part);

		#ifndef NDEBUG
			*indexarr = *max;
			assert ( 0 == spcode_GetCounter(indexarr-(spcode_Iterator_t*)&spcode_def_loc.Counters) );
		#endif
		//GetCounter must return a zero value for the value of the index before the loop starts

		for ( *indexarr = *max;
				 (*indexarr) > 0;
				 --(*indexarr)
				)
		//To avoid side effects using this loop function with recursive functions, the comparison and the incrementation are not
		//bundled together in one command
		{
				dprintf("  Iterat.:%d, &index:%x, Counter: %d\n", *indexarr, indexarr,
					spcode_GetCounter(
						(indexarr-(spcode_Iterator_t*)&spcode_def_loc.Counters)
					)
				);

				spcode_Replicate(indexarr+1/*(unsigned int*)((unsigned char*)max+
					( (unsigned char*)offsetof(spcode_def_counters_t, counters)-
					(unsigned char*)offsetof(spcode_def_counters_t, repeat) ))*/
				);
		}
	}else
	{
		spcode_CopyPart(spcode_def_loc.PartSpec);
		//Pass the pointer to the partdefinition in the same row as given by the main program
		//Starting with index zero. Remember, loops run backwards
	}
	dprintf("...Leaving level:%d\n", ( max-(spcode_Iterator_t*)&spcode_def_loc.Limits ) );
}

//***********************************************************************************
//Initialize the speedcode replication routine
//***********************************************************************************
spcode_t* __fastcall__ spcode_Create(spcode_Spec_t* spdcdef, spcode_t *dest)
{
	//Output debug information, that create_spcode was called
	dprintf("********************************\n"
					"Called \"create_spcode\" with\n"
					"&def = %x, &counters = %x\n"
					"********************************\n", spdcdef, dest);

	//*****************************************
	//Assert valid content of spdcdef structure
	//*****************************************
	//Assert that pointer to spcode_part specifications is not NULL
	assert( (spdcdef -> PartSpec) > 0);

	//Assert number of repeats for all indexes beeing so that total repeats r.x*r.y*r.z*r.part does not multiply to 0
	//assert( (spdcdef -> Limits.x) > 0);
	//assert( (spdcdef -> Limits.y) > 0);
	//assert( (spdcdef -> Limits.z) > 0);
	//assert( (spdcdef -> Limits.Part) > 0);

	//************************************************
	//If no address for dest is given, allocate memory
	//************************************************
	if (!dest)// Explicit assignment, = operator is right here!!!
	//It seems to generate more effective code testing against a variable being not zero and move the code for the zero result
	//outside the if block
	{
		dest = malloc(spcode_CalcSize(spdcdef));
		//dest is not used anymore from now on!
	}

	//memcpy256( sizeof(spcode_def_loc), spdcdef, &spcode_def_loc  );
	spcode_StoreDest = dest;

	//Make local copy of spcode definitions for faster access to struct elements
	spcode_def_loc.Spec = *spdcdef;

	//Calculate offset between index and maxima array, needed in spcode_create_loop(...
	//counter_offset = (uint8_t*)counters - (uint8_t*)&spcode_def_loc.repeat.z;

	//Start recursive procedure for spcode generation
	spcode_Replicate(
		//&spcode_def_loc.repeat.z,
		//&(counters->arr[0])
		&spcode_def_loc.Counters.arr[0]
	);
	/*memcpy returns the destination address. As the address of spdcdef_loc, which is the destination, and the
		address of the array with the repeat limits are equal, the return value of memcpy can be passed through*/

	*(unsigned char*)spcode_StoreDest=RTS;
	return dest;
}

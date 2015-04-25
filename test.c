#include <string.h>
#include "speedcode.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*CC65 Bug: &nameofstruct != nameofstruct
						void (*dest)(void), ++dest increases dest by 2 instead of one!*/

/* Smallest Size: 0x16d*/
						
#ifdef DEBUG
	#define dprintf(...) printf(__VA_ARGS__)
#else
	#define dprintf(...)
#endif


extern union speedcodecountersU speedcodecounters;

extern struct speedcode spdcdef_loc;
static struct speedcodepart spdcpartdef_loc;
void (*storedest)(void);
void __fastcall__ speedcode_create_loop(unsigned int *max);

extern void DELTA;

/*void newloop(unsigned int *max)
{
	dprintf("  Repeat:%d\n", *indexarr);
	speedcode_create_loop(max+1);
}

void copycode(void)
{
	if(NULL != spdcpartdef_loc.callback){spdcpartdef_loc.callback(spdcpartdef_loc.parameters);}
	(unsigned char*)storedest = (unsigned char*)memcpy(storedest, spdcpartdef_loc.speedcodepart, spdcpartdef_loc.size)+spdcpartdef_loc.size;
}
	
void loop (unsigned int * indexarr, void (*func)(void))
{
	for( *indexarr=0;(*indexarr++)<(*max); )
	{
			dprintf("  Repeat:%d\n", *indexarr);
			func();
	}	
}
*/

void __fastcall__ speedcode_create_loop(unsigned int *max)
{
	//The following must be the first line in this routine, because the adress of max must be still in __AX__
	unsigned int *indexarr = (unsigned int*)( (unsigned char)(&DELTA) + __AX__ );
	assert(max); // no NULL Pointer acceptable
	assert(indexarr); // no NULL Pointer acceptable
	
	dprintf("- Called \"create_loop\"\n");
	
	if ( max <= &spdcdef_loc.repeat.index.part )
	{
		dprintf("Count Index:%x, Last Index:%x, Max:%d\n", max,&spdcdef_loc.repeat.index.part, *max);
		for(*indexarr=0; (++(*indexarr))<=(*max);)
		{			
			dprintf("  Repeat:%d\n", *indexarr);
			speedcode_create_loop(++max);
		}
	}else
	{
		dprintf( "-- Inner loop reached. Part = %d\n",*(indexarr-1) );
		dprintf("src:%x, dest:%x\n", spdcdef_loc.codedefines[*(indexarr-1)], &spdcpartdef_loc);
		memcpy(&spdcpartdef_loc, (void*)(spdcdef_loc.codedefines[*(--indexarr)]), sizeof(spdcpartdef_loc));
		/*
		for(speedcodecounters.counters.partrepeat=0;(++speedcodecounters.counters.partrepeat) <= spdcpartdef_loc.repeatcount;)
		{//number of times one speedcodepart is repeated// 
				//dprintf("  Partrepeatcount: %d\n", speedcodecounters.partrepeatcount);
				//if(spdcpartdef_loc.callback){spdcpartdef_loc.callback(spdcpartdef_loc.parameters);}
				(unsigned char*)storedest = (unsigned char*)memcpy(storedest, spdcpartdef_loc.speedcodepart, spdcpartdef_loc.size)+spdcpartdef_loc.size;
		}*/

	}
}


/*void __fastcall__ speedcode_create_loop(unsigned int *max)
{
	static unsigned int *indexarr;
	static signed char j;
	//indexarr = &speedcodecounters.counters.z;
	
	memset(indexarr, 0, sizeof(indexarr)*sizeof(*indexarr));
	
	j=0;
	
loop:
	do
	{
		for (;indexarr=&speedcodecounters.index[j],++(*indexarr)<=*max;)
		{
			dprintf("Level:%d, i:%d\n", indexarr-&speedcodecounters.counters.z,*indexarr);
			
			if ( ++j<=PARTCOUNT_IDX )
			{
				//++indexarr;
				++max;
				goto loop;
			}
			else
			{
				dprintf("Inner loop reached\n");
		
				memcpy(&spdcpartdef_loc, (void*)(spdcdef_loc.codedefines[*indexarr]), sizeof(spdcpartdef_loc));
		
				for(speedcodecounters.counters.partrepeat=0;speedcodecounters.counters.partrepeat < spdcpartdef_loc.repeatcount;
						speedcodecounters.counters.partrepeat++)
				{//number of times one speedcodepart is repeated// 
						//dprintf("  Partrepeatcount: %d\n", speedcodecounters.partrepeatcount);
						if(NULL != spdcpartdef_loc.callback){spdcpartdef_loc.callback(spdcpartdef_loc.parameters);}
						(unsigned char*)storedest = (unsigned char*)memcpy(storedest, spdcpartdef_loc.speedcodepart, spdcpartdef_loc.size)+spdcpartdef_loc.size;
				}
			}
		}
		*indexarr=0;
		--j;
	}
	while(j>=0);
}*/

int __fastcall__ create_speedcode(struct speedcode* spdcdef, void(*dest)(void))
{
	/*Include memory allocation by using information in structs*/
	dprintf("Called \"create_speedcode\" with %x, %x\n", spdcdef, dest);
	if( storedest= dest)
	{/*It seems to genarate more effective code testing against a variable being not zero and move the code for the zero result
			outside the i block*/
		
		speedcode_create_loop( 
			(unsigned int*)(
				(unsigned char*) memcpy( &spdcdef_loc, spdcdef, sizeof(spdcdef_loc) ) + ZREPEAT_IDX
			)
		);
		/*memcpy returns the destination address. As the address of spdcdef_loc, which is the destination, and the 
			address of the array with the repeat limits are equal, the return value of memcpy can be passed through*/
			
		*(unsigned char*)storedest=RTS;
		return EXIT_SUCCESS;	
	}
	return EXIT_FAILURE;
}

			/*(unsigned int*) ( asm("ldy #%o", indexarr),
			asm("inc (sp),y"), // <(*indexarr) 
			asm("bne @l0"),
			asm("iny"),
			asm("inc (sp),y"), // >(*indexarr)
			asm("@l0:"),
			asm("lda (sp),y"), // >(*indexarr)
			asm("ldy #%o+1", max);
			asm("cmp (sp),y"), // >(*max)
			asm("bcc true"), // if >(*max) > >(*indexarr)
			asm("bne false"),
			asm("dey"),
			asm("lda (sp),y"), // <(*max)
			asm("ldy #%o", indexarr),
			asm("cmp (sp),y"), // <(*indexarr)
			asm("bcc false"),
			asm("beq false"),
			asm("true: lda #0"),
			asm("ldx #0"),
			asm("beq @e"),
			asm("false: lda #1"),
			asm("ldx #0"),
			asm("@e:"),
			__AX__;*/
			
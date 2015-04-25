#ifndef __SPDC_H
#define __SPDC_H

#define RTS 0x60

	
.STRUCT speedcodepart
{ speedcodepart .ADDR; unsigned char*
	size .BYTE; unsigned char
	repeatcount .WORD; unsigned int
	callback .ADDR; void (*callback)(unsigned int parameters[])
	parameters .ADDR; unsigned int*
};

#define REPEATS C(z, ZREPEAT_IDX) C(y, YREPEAT_IDX) C(x, XREPEAT_IDX)\
								 C(part, PARTREPEAT_IDX)

enum
{
	#define C(x,y) y,
  REPEATS
  NUMOFLOOPS
  #undef C
};
							 
struct speedcode
{	
	union
	{
		struct
		{
			#define C(x,y) unsigned int x;
			REPEATS
			#undef C
		}index;
		unsigned int arr[NUMOFLOOPS];
	}repeat;
	
	struct speedcodepart *codedefines;
};

#define COUNTERS C(partrepeat, PARTREPEATCOUNT_IDX) C(z,ZCOUNT_IDX) C(y,YCOUNT_IDX)\
								 C(x,XCOUNT_IDX) C(part, PARTCOUNT_IDX)
								 
enum
{
	#define C(x,y) y,
  COUNTERS
  INVALIDCOUNTER
  #undef C
};

union speedcodecountersU{
	#define C(x,y) unsigned int x;
	struct
	{
		COUNTERS
	}counters;
	unsigned int index[INVALIDCOUNTER];
	#undef C
};


int __fastcall__ create_speedcode(struct speedcode* speedcodedef, void(*dest)(void));
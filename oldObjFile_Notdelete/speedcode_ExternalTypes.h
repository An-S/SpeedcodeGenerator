#ifndef __SPEEDC_EXTTYP_H
#define __SPEEDC_EXTTYP_H

#include <stdlib.h>
#include <stdint.h>

//*****************************************
//Elementary types for speedcode generation
//*****************************************
typedef void spcode_Callbackf_t(register void*);
typedef void spcode_t(void);
typedef size_t spcode_Size_t;
typedef void spcode_Assembly_t;
typedef unsigned int spcode_Iterator_t;
typedef void spcode_CallbackParameter_t;

//********************************************
//Macro definitions for generic compound types
//********************************************
#define SPCODE_PART_MEMBERS C(spcode_Template_t, ) C(spcode_Iterator_t, Repeats)\
															C(spcode_Callbackf_t, *Callback) C(spcode_CallbackParameter_t, *Parameters)
															
#define SPCODE_ITERATORS(S,E) C(S, z, E) C(S, y, E) C(S, x, E) C(S, Part, E)
															
//*****************************************
//Compound types for speedcode generation
//*****************************************

//Enumerate the indices of the loop counters respectively the loop limits 
enum
{
	#define C(S,v,E) S##v##E,
	SPCODE_ITERATORS(SPCODE_, _IDX)
	SPCODE_PARTREPEAT_IDX,
  SPCODE_NUMOFLOOPS
  #undef C
};

//Type for short assembly code pieces which are to be replicated
typedef struct
{
	spcode_Assembly_t *AssemblyCode;
	size_t Size;
} spcode_Template_t;
															
//Type for defining how the assembly code pieces are to be replicated in the inner loop
typedef struct 
{ /*spcode_template_spec; //Anonymous Structure, C99 feature
	unsigned int repeatcount;
	callbackf_t *callback;
	void *parameters;*/
	#define C(a,b) a b;
	SPCODE_PART_MEMBERS
	#undef C
} spcode_PartSpec_t;

//Compound type containing all the loop counter variables respectively the loop limits
typedef struct
{
	#define C(S,v,E) spcode_Iterator_t v;
	SPCODE_ITERATORS(,)
	#undef C
}spcode_Iterators_t;

//Compound type containing all the loop counter variables respectively the loop limits
typedef union {
	struct
	{
		spcode_Iterators_t;
		spcode_Iterator_t PartRepeat;
	};
	spcode_Iterator_t arr[SPCODE_NUMOFLOOPS];
}spcode_Counters_t;

//Type for defining how the speedcode is setup from the parts it consists of
typedef struct 
{	
	union
	{
		spcode_Iterator_t arr[SPCODE_NUMOFLOOPS];
		//Unnamed structeres can't be initialized so that the arr must be declared before the structure
		spcode_Iterators_t;
	}Limits;
	//This union must be the first element of the struct spcode, because some code relies on this
	
	spcode_PartSpec_t *PartSpec;
}spcode_Spec_t;

#undef SPCODE_PART_MEMBERS
#undef ITERATORS
//Undef macros because they are not used anymore 
#endif

#ifndef __SPCODE_INTERNAL_H
#define __SPCODE_INTERNAL_H
    #include <assert.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include "speedcode.h"






    //*****************************************
    //Compound types for speedcode generation
    //*****************************************


    //Type for short assembly code pieces which are to be replicated
    struct spcode_Template_tag
    {
        spcode_Assembly_t *AssemblyCode;
        size_t Size;
    } ;

    //Type for defining how the assembly code pieces are to be replicated in the inner loop
    struct spcode_PartSpec_tag
    { /*spcode_template_spec; //Anonymous Structure, C99 feature
        unsigned int repeatcount;
        callbackf_t *callback;
        void *parameters;*/
        #define C(a,b) a b;
        SPCODE_PART_MEMBERS
        #undef C
    };

    //Compound type containing all the loop counter variables respectively the loop limits
    struct spcode_Iterators_tag
    {
        #define C(S,v,E) spcode_Iterator_t v;
        SPCODE_ITERATORS(,)
        #undef C
    };

    //Compound type containing all the loop counter variables respectively the loop limits
    union spcode_Counters_tag
    {
        struct
        {
            spcode_Iterators_t;
            spcode_Iterator_t PartRepeat;
        };
        spcode_Iterator_t arr[SPCODE_NUMOFLOOPS];
    };

    //Type for defining how the speedcode is setup from the parts it consists of
    struct spcode_Spec_tag
    {
        union
        {
            spcode_Iterator_t arr[SPCODE_NUMOFLOOPS];
            //Unnamed structeres can't be initialized so that the arr must be declared before the structure
            spcode_Iterators_t;
        }Limits;
        //This union must be the first element of the struct spcode, because some code relies on this
        spcode_PartSpec_t *PartSpec;
        spcode_Setupf_t *Setup;
        spcode_Teardownf_t *Teardown;
    };

    typedef struct
	{
		spcode_t *StoreDest;
		spcode_Counters_t Counters;
	} spcode_WriteState_t;

    typedef struct
	{
		union
		{
			struct
			{
				spcode_Counters_t Limits;
				spcode_PartSpec_t *PartSpec;
			};
			spcode_Spec_t Spec;
		};
		spcode_WriteState_t;
	} spcode_SpecAndState_t;



    #undef SPCODE_PART_MEMBERS
    #undef ITERATORS

    extern spcode_SpecAndState_t spcode_def_loc;
    extern spcode_PartSpec_t spdcpartdef_loc;

    extern spcode_t *spcode_StoreDest;
	//************
	//Dont use these function prototypes directly
	spcode_t*  __fastcall__ spcode_SetDestination(spcode_t *dest);
	void __fastcall__ spcode_Replicate(register spcode_Iterator_t *indexarr);
	void __fastcall__ spcode_CopyPart(register spcode_PartSpec_t *spcode_partdef);
	//************
    int spcode_InitCounters(register spcode_Spec_t *spec);
    void* fastcall fastmemcpy256(uint8_t n, void *src, void *dest);

    //must be fastcall as they do not care about stack pointer
    void fastcall fastCallback(void* par);
    void fastcall setCallbackJmpAddr(void* jmpaddr);

#endif

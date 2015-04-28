#ifndef __SPEEDC_EXTTYP_H
#define __SPEEDC_EXTTYP_H

#include <stdlib.h>
#include <stdint.h>

//********************************************
//Macro definitions for generic compound types
//********************************************
#define SPCODE_PART_MEMBERS C(spcode_Template_t, )\
    C(spcode_Iterator_t, Repeats)\
    C(spcode_Setupf_t, *Setup)\
    C(spcode_Callbackf_t, *Callback)\
    C(spcode_Teardownf_t, *Teardown)\
    C(spcode_CallbackParameter_t, *Parameters)

#define SPCODE_ITERATORS(S,E) C(S, z, E) C(S, y, E) C(S, x, E) C(S, Part, E)


//Enumerate the indices of the loop counters respectively the loop limits
enum
{
    #define C(S,v,E) S##v##E,
    SPCODE_ITERATORS(SPCODE_, _IDX)
    SPCODE_PARTREPEAT_IDX,
  SPCODE_NUMOFLOOPS
  #undef C
};

//*****************************************
//Elementary types for speedcode generation
//*****************************************
typedef void fastcall spcode_Setupf_t(void*);
typedef void fastcall spcode_Callbackf_t(void);
typedef void fastcall spcode_Teardownf_t(void*);
typedef void spcode_t(void);
typedef size_t spcode_Size_t;
typedef void spcode_Assembly_t;
typedef size_t spcode_Iterator_t;
typedef void spcode_CallbackParameter_t;

typedef union spcode_Counters_tag spcode_Counters_t;
typedef struct spcode_Spec_tag spcode_Spec_t;
typedef struct spcode_Iterators_tag spcode_Iterators_t;
typedef struct spcode_PartSpec_tag spcode_PartSpec_t;
typedef struct spcode_Template_tag spcode_Template_t;

//Undef macros because they are not used anymore
#endif

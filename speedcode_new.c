#include "speedcode_Internal.h"

spcode_Spec_t *speedcode_new(void){
    spcode_Spec_t *tmp = malloc(sizeof(spcode_Spec_t));
    uint8_t i;

    assert(NULL != tmp);

    spcode_InitCounters(tmp);
    return tmp;
}

#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>

#include "speedcode_Internal.h"

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

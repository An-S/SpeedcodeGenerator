#ifndef __TESTSPDC_H
#define __TESTSPDC_H
#include <stdint.h>

typedef struct
{
	uint8_t* srcstartadr;
	uint8_t* deststartadr;
} spcodepart_parameters;

typedef struct
{
	uint8_t cmd1;
	uint8_t* src;
	uint8_t cmd2;
	uint8_t* dest;
} spcodepart_variables;

void fastcall modspcode(void);


extern spcodepart_variables testspcode;
extern const unsigned char spcodelen;

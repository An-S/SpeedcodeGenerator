#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef unsigned char u1_t;
typedef unsigned char u2_t;
typedef unsigned char u3_t;

typedef enum {a,b,c} e1_t;

u1_t bla = (u2_t)10;
e1_t suelz = b;
unsigned char  blub = b;
//unsigned long int suc = (unsigned long int)asm("lda $ffff");

typedef void fptr_t(void);

fptr_t* test(void)
{
	//uintptr_t blub = (uintptr_t)&label1;

	//label1:
	asm("lda $ffff");
	//label2:
	return NULL;
}

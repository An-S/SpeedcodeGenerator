#include <stdio.h>

typedef union 
{
	struct
	{
		unsigned char lowb;
		unsigned char hib;
	};
	unsigned int word;
} uint16_littleendian_t;

union
{
	uint16_littleendian_t array[10];
	unsigned char chararray[20];
} data;

//uint16_littleendian_t array[10] = {{1},{2},{3},{4},{5},{6},{7},{8},{9},{10}};

unsigned int __fastcall__ getElement(unsigned char index)
{
	/*asm("ldy #%o",index);
	asm("lda (sp),y");
	asm("asl");
	asm("tay");
	asm("ldx %v+1,y", array);
	asm("lda %v,y",array);
	
	return __AX__;*/

	return *( (unsigned int*)((unsigned char*)&data+(index<<1)) );
}

void main(void)
{
	unsigned char i;
	
	for (i=0; i< sizeof(data.array)/sizeof(data.array[0]); i++)
	{
		printf("%d\n", getElement(i));
	}
	
}

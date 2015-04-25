#include <stdio.h>

struct test{
	unsigned char* bar;
};

int main(void){
	unsigned char *text ="Stefan";
	unsigned int *p;
	struct test foo;
	
	foo.bar = text;
		
	//printf("%x",foo->bar);
	p++;
}

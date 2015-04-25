#include <stdio.h>
#include <conio.h>

void test (void)
{
	printf("Function call successfull\n");
}

struct func_ptr_su
{
 		void (*func)(void);
} func_ptr =
{
	test
};



int main(void)
{ struct func_ptr_su* fptr = &func_ptr;

	printf("func_ptr.func();\n");
	func_ptr.func();
	cgetc();
	printf("fptr->test();\n");
	fptr->func();
	cgetc();
  printf("(*fptr).test();\n");
	(*fptr).func();
	return 0;
}


		


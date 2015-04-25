#include <stdio.h>

void recursion(int i)
{
	int j;
	
	if(i<4)
	{
		
		for (j=0;j<=i;j++)
		{
			printf("i,j: %d, %d\n",i,j);
			recursion(i+1);
		}
	}
}

void main(void)
{
	recursion(1);
}

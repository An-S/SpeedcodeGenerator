#include <stdio.h>

void main(void){
	static signed char i[3]={-1,-1,-1};
	static signed char j = 0;
	static signed char* k=i;
	
loop:
	do
	{
		for (;((*k)++)<3;)
		{
			printf("j:%d, i:%d\n", k-i,*k);
			
			if ( k<&i[sizeof(i)-1] )
			{
				++k;
				goto loop;
			}
	
		}
		*k=-1;
		--k;
	}
	while(k>=i);
}

	
#include <stdio.h>
#include <string.h>

int main(void)
{
	unsigned char teststr[] ="Hello, world\n";
	printf("%d",memcpy((unsigned char*)0x400, teststr, sizeof(teststr) ) );

	
	return 0;
}

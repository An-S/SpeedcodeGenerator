#include <stdio.h>
#include <conio.h>

struct 
{
	int x;
	int y;
} coord[] = 
{
	{0,0},{0,10},{10,0},{10,10}
};

struct 
{
	int n;
	struct coord *coordarr;
} coordinates;

void main(void)
{
	//coordinates.coordarr = &(coord[0]);
	printf("bla");
}

void main(void)
{
	static struct coord
	{
		int x;
		int y;
	}coord=
	{
		1,2
	};
	
	static struct coord coord2=
	{
		3,4
	};
	
	coord.x=10;
	coord2.y=20;
	
}

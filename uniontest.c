void main(void)
{
	static union
	{
		struct 
		{
			int x,y;
		}coord;
		unsigned long l;
	}u;
	
	u.coord.x=10;
	u.coord.y=20;
	u.l=0x70000;
}

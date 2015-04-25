#include <stdio.h>
#include <spr.h>
#include <conio.h>

void sprarr = {(unsigned char)8, (int)(-48-8), (int)0x198, (int)1, 
							 (int)(24+0*48), (int)(24+1*48), (int)(24+2*48), 
							 (int)(24+3*48), (int)(24+4*48), (int)(24+5*48), 
							 (int)(24+6*48), (int)(24+7*48)};
								 
int main(void){
	do{/*
		printf("%d %d %d %d %d %d %d %d %d %d %d %d",
			(unsigned char)(&sprarr)[0]),
			(int)(sprarr+1)),
			(int)&(sprarr+3),
			(int)&(sprarr+5),
			(int)&(sprarr+7),
			(int)&(sprarr+9),
			(int)&(sprarr+11),
			(int)&(sprarr+13),
			(int)&(sprarr+15),
			(int)&(sprarr+17),
			(int)&(sprarr+19),
			(int)&(sprarr+21));
		*/
		while(!kbhit());
	}		
	while(cgetc != 'q');
}

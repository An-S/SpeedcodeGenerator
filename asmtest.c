void main(void){
	static unsigned int a,b;
	static char c,d;
	
	asm("lda #<(%v-%v)", a,b);
	asm("sta %v",c);
	
}

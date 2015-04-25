.INCLUDE "c64.inc"

.EXPORT setnsprx
.IMPORT ldaidxadr,ldaffffidx
.PROC setnsprx
	asl
	tay
	tya
	asl
	sta setxloop+1
	txa
setxloop:
	sta VIC_SPR0_X,y
	dey
	dey
	bpl	setxloop

	rts
.ENDPROC
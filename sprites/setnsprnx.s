.INCLUDE "c64.inc"

.EXPORT setnsprnx
.IMPORT ldaidxadr,ldaffffidx
.PROC setnsprnx
	stx ldaidxadr
	sty ldaidxadr+1
	tax
	jsr ldaffffidx
	sta VIC_SPR_HI_X
	dex
	txa
	asl
	tay
setxloop:
	jsr ldaffffidx
	sta VIC_SPR0_X,y
	dey
	dey
	dex
	bpl	setxloop

	rts
.ENDPROC
.INCLUDE "c64.inc"

.EXPORT setnsprcol
.IMPORT ldaffffidx,ldaidxadr

.PROC setnsprcol
	stx colsrc
	sty colsrc+1
	tax
setxloop:
colsrc=*+1
	lda $ffff,x
	sta VIC_SPR0_COLOR,x
	dex
	bpl	setxloop

	rts
.ENDPROC
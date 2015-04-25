.INCLUDE "c64.inc"

;x:n, y:y-coord, a:1stspr 
.EXPORT setnspry, __setnspry=setnspry
.PROC setnspry
	stx lastspr
	
	ldx #0
	ldy #0
setyloop:
	sta VIC_SPR0_Y,x
	inx
	inx
	iny
lastspr = *+1
	cpy #0
	bne	setyloop

	rts
.ENDPROC
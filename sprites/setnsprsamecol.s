.INCLUDE "c64.inc"

.EXPORT setnsprsamecol,__setnsprsamecol

__setnsprsamecol:
.PROC setnsprsamecol
	dex
	bmi end
setxloop:
	sta VIC_SPR0_COLOR,x
	dex
	bpl	setxloop
end:
	rts
.ENDPROC
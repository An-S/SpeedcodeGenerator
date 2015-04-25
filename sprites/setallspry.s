.INCLUDE "c64.inc"

.EXPORT setallspry

.PROC setallspry
	sta VIC_SPR0_Y
	sta VIC_SPR1_Y
	sta VIC_SPR2_Y
	sta VIC_SPR3_Y
	sta VIC_SPR4_Y
	sta VIC_SPR5_Y
	sta VIC_SPR6_Y
	sta VIC_SPR7_Y
	rts					
.ENDPROC

.INCLUDE "c64.inc"
SPRW = 24

.EXPORT setnsprxinrow,__setnsprxinrow=setnsprxinrow

.PROC setnsprxinrow
	.IMPORT powertable,popa
	.IMPORTZP tmp1
	sprxhi = tmp1
	
	stx sprxhi
	sta lastsprnum
	jsr popa
	
	ldy #0
	ldx #0
	
	sta VIC_SPR0_X,x
setxloop:	
	clc
	lda VIC_SPR_EXP_X
	and powertable,y
	beq :+
	lda #2*SPRW
	.BYTE $2c  ;Attention! Carry flag is not preserved, if two
						;additions are used here.
:	lda #SPRW
	adc VIC_SPR0_X,x
	sta VIC_SPR0_X+1,x
	bcc :+
	
	inc sprxhi
: lda sprxhi
	beq :+
	
	lda VIC_SPR_HI_X
	ora powertable+1,y
	sta VIC_SPR_HI_X
:	
	inx
	inx
	iny
lastsprnum=*+1
	cpy #0
	bne setxloop
	rts
.ENDPROC

	
.INCLUDE "c64.inc"
.INCLUDE "stack\stack.i"

.EXPORT setnsprdefinrow
.IMPORT ldaffffidx,ldaidxadr

;in:a=scrhi, x:N spr, y=startsprpointer
.EXPORT setnsprdefinrow,__setnsprdefinrow=setnsprdefinrow
.PROC setnsprdefinrow
	.IMPORTZP tmp1
	.IMPORT popa
	
	clc
	adc #3
	sta scrdest
	stx lastsprnum
	
	jsr popa
	tay

	ldx #0
setdefloop:
	tya
scrdest=*+2
	sta $fff8,x
	iny
	inx
lastsprnum = *+1
	cpx #$00
	bne	setdefloop

	rts
.ENDPROC
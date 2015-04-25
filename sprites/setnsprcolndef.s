.INCLUDE "c64.inc"
.INCLUDE "stack\stack.i"

.EXPORT setnsprcolndef
.IMPORT ldaffffidx,ldaidxadr

;x/y adress of table with data, a amount of spr, stack srcdest
.PROC setnsprcolndef
	stx ldaidxadr
	sty ldaidxadr+1
	tsx
	ldy STACK+3,x
	iny
	iny
	iny
	sty scrdest+1
	
	tax
	lsr
	tay
setloop:
	jsr ldaffffidx
	sta VIC_SPR0_COLOR,y
	dex
	jsr ldaffffidx
scrdest=*+1
	sta $fff8,y
	dex
	bpl	setloop

	rts
.ENDPROC
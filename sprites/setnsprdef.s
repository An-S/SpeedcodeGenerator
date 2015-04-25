.INCLUDE "c64.inc"
.INCLUDE "stack\stack.i"

.EXPORT setnsprdef
.IMPORT ldaffffidx,ldaidxadr

;x/y adress of table with data, a amount of spr, stack srcdest
.PROC setnsprdef
	stx defsrc
	sty defsrc+1+1
	tsx
	ldy STACK+3,x
	iny
	iny
	iny
	sty scrdest+1
	tax
setxloop:
defsrc=*+1
	lda $ffff,x
scrdest=*+1
	sta $fff8,x
	dex
	bpl	setxloop

	rts
.ENDPROC
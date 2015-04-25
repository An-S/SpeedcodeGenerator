.EXPORT decarray16, _decarray16
.IMPORTZP ptr1, tmp1, tmp2, tmp3

;MAXIMUM ARRAY LEN = 255 (0=256)
lenofs = 0
lowestofs = 2
highestofs = 4
stepofs = 6
dataofs = 8

decarray16:
_decarray16:
	sta ptr1
	stx ptr1+1
	
	ldy #lenofs
	lda (ptr1),y
	tax
	;ignore highbyte for now
	ldy #highestofs
	lda (ptr1),y
	sec
	ldy #lowestofs
	sbc (ptr1),y
	sta deltahighlowlo
	ldy #highestofs+1
	lda (ptr1),y
	ldy #lowestofs+1
	sbc (ptr1),y
	sta deltahighlowhi

	ldy #dataofs
	sty counter
loop:
	ldy counter
	lda (ptr1),y ;load first lobyte to decrement it
	ldy #stepofs
	sec
	sbc (ptr1),y ;substract stepsize
	ldy counter
	sta (ptr1),y
	sta tmp1
		
	iny
	sty tmp3
	lda (ptr1),y ;same with hibyte
  ldy #stepofs+1
	sbc (ptr1),y
	sta tmp2
	ldy tmp3
	sta (ptr1),y
	bcc reset ;if underflow, always reset value
	ldy #lowestofs+1
  cmp (ptr1),y ;if no underflow, test if passed lowest possible value
  bcc reset ;if lowesthi > valuehi => lowest > value, so reset
	bne next ;if lowesthi <> valuehi => lowest < value, so no reset

	lda tmp1
	dey
	cmp (ptr1),y ;check, if lowestlo > valuelo
	bcs next ;no, then ok and store else reset
reset:
	lda tmp1
	sec
deltahighlowlo = *+1
	adc #0 
	ldy counter
	sta (ptr1),y
	lda tmp2
deltahighlowhi = *+1
	adc #0;add the difference between highest and lowest plus one
	iny
	sta (ptr1),y
next:
	inc counter
	inc counter
  dex
  bne loop
  
  rts
counter: .res 1 
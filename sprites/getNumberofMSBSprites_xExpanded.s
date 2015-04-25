xReferenceCoordinate = 32
xSpriteCharWidth = 6

.EXPORT getNumberOfMSBSprites_xExpanded
.EXPORT _getNumberOfMSBSprites_xExpanded = getNumberOfMSBSprites_xExpanded
.PROC getNumberOfMSBSprites_xExpanded
;In: accu = x Position of first sprite in chars
	tay
	bmi end
	
	ldx #32
	stx xReferenceCoordinate ;Reference coordinate over which one sprite is added to MSB region
	
	ldy #$ff>>0
	cmp #xReferenceCoordinate
	bcs setMSB
	clc
	adc #xSpriteCharWidth
	ldy #$ff>>1
	cmp #xReferenceCoordinate
	bcs setMSB
	clc
	adc #xSpriteCharWidth
	ldy #$ff>>2
	cmp #xReferenceCoordinate
	bcs setMSB
	clc
	adc #xSpriteCharWidth
	ldy #$ff>>3
	cmp #xReferenceCoordinate
	bcs setMSB
	clc
	adc #xSpriteCharWidth
	ldy #$ff>>4
	cmp #xReferenceCoordinate
	bcs setMSB
	clc
	adc #xSpriteCharWidth
	ldy #$ff>>5
	cmp #xReferenceCoordinate
	bcs setMSB
	clc
	adc #xSpriteCharWidth
	ldy #$ff>>6
	cmp #xReferenceCoordinate
	bcs setMSB
	clc
	adc #xSpriteCharWidth
	ldy #$ff>>7
	cmp #xReferenceCoordinate
	bcs setMSB
setMSB: 
	sty $d010
end:
	rts
.ENDPROC

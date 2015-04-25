.AUTOIMPORT on
.IMPORTZP ptr1

.EXPORT _generate_scrollspeedcode

_generate_scrollspeedcode:
	sta ptr1
	stx ptr1+1

gen:
foronepage:
	ldy #<_scrollcodelen-1
copycode:
	lda _scrollcode,y
	sta (ptr1),y
	dey
	bpl copycode

	ldx #ptr1
	lda #<_scrollcodelen
	jsr addzp

	inc modsource
	bne :+
	inc modsource+1
:
	inc moddest
	bne :+
	inc moddest+1
:
	dec bytestoscroll
	bne gen
	dec bytestoscroll+1
	bne gen

	lda #$60
	sta (ptr1),y
	rts

_scrollcode:
modsource = *+1
	lda !$0,x
	;source,x
moddest = *+1
	sta !$0
	;dest
_endscrollcode:

_scrollcodelen = _endscrollcode-_scrollcode
bytestoscroll:
	.WORD 1000

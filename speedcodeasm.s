.macpack longbranch

.autoimport on

.FEATURE labels_without_colons
.IMPORTZP ptr1,ptr2

.PUSHSEG
.BSS

.EXPORT _spdcdef_loc = *
.RES 10

.EXPORT _speedcodecounters=*
.RES 10

.POPSEG
.EXPORT _DELTA = _speedcodecounters - _spdcdef_loc

.EXPORT _setCallbackJmpAddr
.PROC _setCallbackJmpAddr
.IMPORT _jmpdest
.EXPORT rtscode
    tay
    bne setaddr
    cpx #0
    bne setaddr
    lda #<rtscode
    ldx #>rtscode
setaddr
    sta _jmpdest
    stx _jmpdest+1
rtscode
    rts

.ENDPROC

.EXPORT _fastCallback
.PROC _fastCallback
.EXPORT _jmpdest
.IMPORT rtscode
;    tay
;    bne pushparams
;    cpx #0
;    beq nopush
;pushparams
;    jsr pushax
;nopush
_jmpdest = *+1

    jmp rtscode
.ENDPROC

.EXPORT _fastmemcpy256
.PROC _fastmemcpy256
    sta ptr2
    stx ptr2+1
    jsr popax
    sta ptr1
    stx ptr1+1
    jsr popa
	tax ;x is not used else for copying
	tay
copyagain
    cpy #16
    bcs jd0
    tya
    and #15
    asl
    sta jmpdest
jmpdest = *+1
    bcc :+
    :
.repeat 16,i
    bcc .ident(.sprintf("jd%d",16-i))
.endrep

.REPEAT 16,i
.ident(.sprintf("jd%d",i))
    dey
    lda (ptr1),y
    sta (ptr2),y
.ENDREPEAT
jd16
    cpy #0
    jne copyagain

    txa
    clc
    adc ptr2
    ldx ptr2+1
    bcc :+
    inx
    :
    rts
.ENDPROC

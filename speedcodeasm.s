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

.EXPORT _fastmemcpy256
.PROC _fastmemcpy256
    sta ptr2
    stx ptr2+1
    jsr popax
    sta ptr1
    stx ptr1+1
    jsr popa

    ;lda #$15;size
    tay
copyagain
    dey
    cpy #15
    bcs jd0

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
    lda (ptr1),y
    sta (ptr2),y
    dey
.ENDREPEAT
jd16
    cpy #$ff
    beq raus
    iny
    tya
    jne copyagain
raus
    rts
.ENDPROC

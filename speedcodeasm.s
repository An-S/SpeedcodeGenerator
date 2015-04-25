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

copy
    lda #5;size
    tay
copyagain
    dey
    and #15
    asl
    sta jmpdest
jmpdest = *+1
    bcc :+
    :
.repeat 16,i
    bcc .ident(.sprintf("@jd%d",16-i))
.endrep

.REPEAT 16,i
.ident(.sprintf("@jd%d",i))
    lda (ptr1),y
    sta (ptr2),y
    dey
.ENDREPEAT
@jd16
    cpy #$ff
    beq raus
    iny
    tya
    bne copyagain
raus

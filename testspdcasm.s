.PROC _testspcode

.EXPORT _srcadr, _destadr, _testspcode
.EXPORT _spcodelen


  lda $0400
_srcadr=*-2
	sta $03ff
_destadr=*-2
_testspcodeend:

_spcodelen = _testspcodeend-_testspcode
.ENDPROC
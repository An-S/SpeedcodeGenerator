
test.c: 
	@echo $(@:.c=_dbg.o)
	
all: test.c
	
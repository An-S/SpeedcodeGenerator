BASE = speedcode

DEBUG = -D NDEBUG

INCLUDE = ..\..\include
CFLAGS = -I$(INCLUDE) -tc64 -Oirs -l $(*F).lst -m $(*F).map -Ln $(*F).lbl $(DEBUG)
LIBDIR = ..\..\lib
LIB = $(LIBDIR)\carlos.lib

HEADERS = $(BASE).h opcodes_incl_illegals.h
OBJECTS = calc_$(BASE)size.o $(BASE)_getcounter.o $(BASE).o 

%.o: %.c
		cl65 $(CFLAGS) -c $< -o $@

%.o: %.s
		cl65 $(CFLAGS) -c $< -o $@

all: $(HEADERS) $(OBJECTS)
		 ar65 a $(LIB) $(OBJECTS)
		 xcopy /y $(BASE).h $(INCLUDE)\$(BASE)
		 xcopy /y opcodes_incl_illegals.h $(INCLUDE)\$(BASE)
		 xcopy /y speedcode_ExternalTypes.h $(INCLUDE)\$(BASE)
		 xcopy /y speedcode_macros.h $(INCLUDE)\$(BASE)







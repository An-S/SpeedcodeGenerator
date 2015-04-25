INC = ..\..\include
cflags = -tc64 -l $(basename $(*F)).lst -I$(INC)
LIB = ..\..\lib

objects = setnsprsamecol.o setnsprdefinrow.o setnsprxinrow.o\
				  sprdecx.o setnspry.o setnsprx.o\
					setnsprnx.o setnsprdef.o setnsprcolndef.o	setnsprcol.o\
					setallspry.o getNumberofMSBSprites_xExpanded.o			
					
all:  $(objects)

%.o:	%.s
	ca65 $(cflags) $< -o $@
	ar65 d $(LIB)\carlos.lib $@
	ar65 a $(LIB)\carlos.lib $@

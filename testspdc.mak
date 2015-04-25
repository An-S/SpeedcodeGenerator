BASE = testspdc

INCLUDE = ..\..\include
LIB = $(HOMEPATH)\Documents\C64\Coding\lib

CFLAGS = -I$(INCLUDE) -tc64 -Oirs -l $(patsubst %.run, %.lst, $(@:.o=.lst))\
																  -m $(patsubst %.run, %.map, $(@:.o=.map))\
																	-Ln $(patsubst %.run, %.lbl, $(@:.o=.lbl))

HEADERS = $(BASE).h speedcode.h
OBJECTS = $(BASE).o testspdcasm.o calc_speedcodesize.o speedcode_getcounter.o speedcode.o

%.o: %.c
		cl65 $(CFLAGS) -o $@ -D NDEBUG -c $< 
%_dbg.o: %.c
		cl65 $(CFLAGS) -o $@ -c $< 

%.o: %.s
		cl65 $(CFLAGS) -o $@ -D NDEBUG -c $< 

%_dbg.o: %.s
		cl65 $(CFLAGS) -o $@ -c $< 

all: $(BASE)_dbg.run $(BASE).run 

$(BASE).run: $(HEADERS) $(OBJECTS) 
		@echo linking final version
		cl65 $(CFLAGS) -o $@ $(OBJECTS) $(LIB)\carlos.lib 
		

$(BASE)_dbg.run: $(HEADERS) $(OBJECTS:.o=_dbg.o)
		@echo linking debug version
		cl65 $(CFLAGS) -o $@ $(OBJECTS:.o=_dbg.o) $(LIB)\carlos.lib 
		
clean:
		@rm *.o, *.run, *.lst, *.map, *.lbl

		 




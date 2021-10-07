# Type: Make runsim
# Source Files: runsim.c testsim.c license.c config.h
# Object files: runsim.o testsim.o license.o

IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = runsim.c testsim.c license.c config.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = runsim.o testsim.o license.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

runsim: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

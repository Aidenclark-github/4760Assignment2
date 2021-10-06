# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# Source Files: runsim.c testsim.c license.c config.h
# Object files: runsim.o testsim.o license.o
# Type: Make sim
    

CC = gcc
CFLAGS  = -g -Wall

sim:  runsim.o testsim.o license.o 
	$(CC) $(CFLAGS) -o sim runsim.o testsim.o license.o

runsim.o:  runsim.c 
	$(CC) $(CFLAGS) -c runsim.c

testsim.o:  testsim.c 
	$(CC) $(CFLAGS) -c testsim.c

license.o:  license.c 
	$(CC) $(CFLAGS) -c license.c

clean: 
	$(RM) sim *.o *~

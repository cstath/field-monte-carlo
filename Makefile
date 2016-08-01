# #####################   Makefile.1   #######################

OBJS   = main.o fields.o options.o met.o action.c measure.o drandom.o
CFLAGS = -ggdb3 -Wall -Wextra -std=c99 -pedantic
LIBS   = -lm 

metropolis: $(OBJS)
	$(CC)  $(CFLAGS) $^   -o $@ $(LIBS)

$(OBJS): common.h met.h measure.h fields.h action.h options.h drandom.h

clean:
	/bin/rm -f *.o metropolis

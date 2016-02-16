# ########################   Makefile.1   ############################
# $@ target, $< first dependency, $^ all dependencies, 
# $* "stem" of target filename e.g. %.f: %.F will five foo for foo.f

OBJS   = main.o fields.o options.o init.o met.o action.c measure.o printmatrix.o drandom.o
CFLAGS = -O2 -ggdb3 -Wall -Wextra -std=c99 -pedantic
LIBS   = -lm 

metropolis: $(OBJS)
	$(CC)  $(CFLAGS) $^   -o $@ $(LIBS)

$(OBJS): include.h fields.h printmatrix.h action.h options.h

clean:
	/bin/rm -f *.o metropolis core*

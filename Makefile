# ########################   Makefile.1   ############################
# $@ target, $< first dependency, $^ all dependencies, 
# $* "stem" of target filename e.g. %.f: %.F will five foo for foo.f

OBJS   = main.o init.o met.o action.c measure.o drandom.o printmatrix.o drandom.o
CFLAGS = -O2
LIBS   = -lm

metropolis: $(OBJS)
	$(CC)  $(CFLAGS) $^   -o $@ $(LIBS)

$(OBJS): include.h printmatrix.h action.h

clean:
	/bin/rm -f *.o metropolis core*

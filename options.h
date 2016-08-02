/************************ options.h ************************/
#ifndef OPTIONS_H
#define OPTIONS_H

#include <getopt.h>
#include <string.h>
#include <libgen.h>
#include <time.h>
#include "common.h"
#include "drandom.h"

typedef struct options_structure {

	int L;	// lattice dimentions size
	double MU;	// chemical potential
	int silent; // silent output mode
	int nmeasurements; // number of total measurements
	long seed;	// seed initial value for the random number generator

} options;

// prints out usage instructions
void usage();

// prints out an error message
void locerr( char *errmes );

// Get the options function: See "man 3 getopt" for usage
options get_the_options(int argc, char **argv);

// prints simulation options setup
void simmessage(FILE *fp, options shelloptions);

#endif
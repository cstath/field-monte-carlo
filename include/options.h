/************************ options.h ************************/
#ifndef OPTIONS_H
#define OPTIONS_H

/**
 * @file options.h
 * Parsing of the command line arguments to get user's options
 */

#include <getopt.h>
#include <string.h>
#include <libgen.h>
#include <time.h>
#include "common.h"
#include "drandom.h"

/** A structure to hold the parameters given by the user in the command line */
typedef struct options_structure {

	int L;	///< lattice dimentions size
	double M; ///< field's mass
	double LAMBDA; ///< field's coupling constant
	double MU;	///< chemical potential
	int silent; ///< silent output mode
	int nmeasurements; ///< number of total measurements
	long seed;	///< seed initial value for the random number generator

} options;

/** prints out usage instructions */
void usage();

/** prints out an error message 
 *	@param errmes error message */
void locerr( char *errmes );

/** Get the options function: See "man 3 getopt" for usage */
options get_the_options(int argc, char **argv);

/** prints simulation options setup 
 *	@param fp output file descriptor
 *	@param shelloptions a structure with options from the shell */
void simmessage(FILE *fp, options shelloptions);

#endif
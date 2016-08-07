/************************ main.c ************************/
#include "common.h"
#include "fields.h"
#include "options.h"
#include "met.h"
#include "measure.h"

int main(int argc, char **argv) {

	// user defined shell options
	options opts;
	opts = get_the_options(argc, argv);

	// Create a field with the specified parameters
	field phi = create_field(opts.L, opts.M, opts.LAMBDA, opts.MU);

	// perform metropolis sweeps
	int i;
	for ( i = 0; i < opts.nmeasurements; i++) {
		met(&phi);	// update the field according to metropolis algorithm
		measure(phi);	// measure observables
	}

	destroy_field(&phi);

}

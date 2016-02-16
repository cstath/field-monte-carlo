/************************   main.c ********************************/
#include "include.h"
#include "fields.h"
#include "options.h"

int main(int argc, char **argv){

	int isweep, imeasurement;
	/*define parameters from options:*/
	MU=-1.;nsweep=-1;nmeasurement=-1;start=-1; silent=0; seed=9873;
	get_the_options(argc,argv);

	// Create a field / maybe use malloc instead
	artype phi[L][L][L][L];

	// initialize field
	init(start, phi);

	// perform metropolis sweeps
	for(imeasurement=0;imeasurement<nmeasurement;imeasurement++){
		for(isweep=0;isweep<nsweep;isweep++){
			met(phi);
		}
		measure(phi);
	}

}

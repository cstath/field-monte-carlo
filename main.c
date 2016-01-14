/************************   main.c ********************************/
#include "include.h"
#include "printmatrix.h"

int main(int argc, char **argv){

	int start=0;
	int isweep,nsweep = 1000;
	//beta=0.21;
	seed=9873;
	start=0;

	// Create a field
	artype phi[L][L];

	// initialize field
	init(start, phi);

	// perform metropolis sweeps
	for(isweep=0;isweep<nsweep;isweep++){
		met(phi);
		measure(phi);
	}

}

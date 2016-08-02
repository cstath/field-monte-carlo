/************************ met.c ************************/
#include "met.h"

void met(field *pfield)
{	/* Performs a metropolis algorithm sweep */
	int L = pfield->L;
	int N = pfield->N;
	artype **** fieldlat = pfield->lattice;

	int n1, n2, n3, n4, k;
	fieldpos n;
	artype newvalue;
	artype deltacomplex;
	double delta;
	static int acceptedstates=0, dropedstates=0;

	for(k = 0; k < N; k++){
		//pick a random site n=(n1,n2,n3,n4) on the field lattice
		n1 = L*drandom();
		n2 = L*drandom();
		n3 = L*drandom();
		n4 = L*drandom();
		n.n1=n1; n.n2=n2; n.n3=n3; n.n4=n4;
	
		// New value for the field phi at site n. phi -> phi+D_phi
		newvalue = fieldlat[n1][n2][n3][n4] + D_Phi*( (2*drandom()-1) + (2*drandom()-1)*I ) ;

		// Calculate change in action between the new and the old field state
		deltacomplex = deltaS(pfield, newvalue, n);
		delta = creal(deltacomplex);

		// Decide whether the new state is to be accepted or not
		if ( (delta <=0 ) || (drandom()<exp(-delta)) )
		{ 	// Accepted!
			fieldlat[n1][n2][n3][n4] = newvalue; 
			acceptedstates++;
		} 
		else
		{ 	// Not accepted
			dropedstates++;
		}
		
	}//sweep ends

	if (!silent)
		printf("Acceptance Ratio: %f\n", (1.0*acceptedstates)/(acceptedstates+dropedstates));
}

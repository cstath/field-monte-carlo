/************************   met.c *********************************/
#include "include.h"
#include "action.h"
#include "printmatrix.h"

void met(artype phi[L][L])
{	/* Performs a metropolis algorithm sweep */
	int n1, n2, k;
	artype newvalue, s1, s2, delta;
	static int acceptedstates=0, dropedstates=0;

	for(k=0;k<N;k++){
		//pick a random site n1,n2
		n1 = L*drandom(); 
		n2 = L*drandom();
	
		// New value for the field phi at site n1,n2. phi -> phi+D_phi
		newvalue = phi[n1][n2] + D_Phi*(2*drandom()-1); // or RANDSIGN;

		// Calculate change in action between the new and the old field state
		delta = deltaS(phi, newvalue, n1, n2);

		/*phi2[n1][n2] = newvalue;
		s1=Saction(phi);
		s2=Saction(phi2);
		printf("Phi\n");
		printf("s1: %d\n\n", s1);
		printf("Phi2\n");
		printf("s2: %d\n\n", s2);
		printf("s1: %d\ns2: %d\ndifference: %d\n\n", s1, s2, s2-s1);*/
		
		// Decide whether the new state is to be accepted or not
		if ( (delta <=0 ) || (drandom()<exp(-delta)) )
		{ 	// Accepted!
			phi[n1][n2] = newvalue; 
			acceptedstates++;
			#ifdef VERBOSE_MODE
			printmatrixColorPoint(phi, n1, n2);
			#endif
		} 
		else
		{ 	// Not accepted
			//phi2[n1][n2] = phi[n1][n2];
			dropedstates++;
		}

		//printf("Accepted States: %d\nDroped States: %d\n\n", acceptedstates, dropedstates);
		printf("Acceptance Ratio: %f\n\n", (1.0*acceptedstates)/(acceptedstates+dropedstates));

	}//sweep ends
}

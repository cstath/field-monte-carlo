/************************   met.c *********************************/
#include "include.h"

void met(artype phi[L][L])
{
	int n1, n2, k;
	artype newvalue, s1, s2, delta;

	for(k=0;k<N;k++){
		//pick a random site n1,n2
		n1= L*drandom(); 
		n2= L*drandom();
	
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
		{ 	//accept
			phi[n1][n2] = newvalue; 
			//printf("Accepted!\n");
			acceptedstates++;
			//printmatrix(phi);
			printmatrixColor(phi, n1, n2);
		} 
		else
		{ 	// do not accept
			//phi2[n1][n2] = phi[n1][n2]; 
			//printf("Not accepted\n");
			dropedstates++;
		}
		//printf("Accepted States: %d\nDroped States: %d\n\n", acceptedstates, dropedstates);
		//printf("Acceptance Ratio: %f\n\n", (1.0*acceptedstates)/(acceptedstates+dropedstates));
		

	}//sweep ends
}

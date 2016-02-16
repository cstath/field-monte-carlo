/************************   met.c *********************************/
#include "include.h"
#include "fields.h"
#include "action.h"
#include "printmatrix.h"

#define PRINT_CMPLX(x) printf("%.15f%+.15fi\n", creal(x), cimag(x))

void met(artype phi[L][L][L][L])
{	/* Performs a metropolis algorithm sweep */
	int n1, n2, n3, n4, k;
	fieldpos n;
	artype newvalue;
	artype s1, s2, deltacomplex, difference;
	double delta;
	static int acceptedstates=0, dropedstates=0;

	for(k=0;k<N;k++){
		//pick a random site n1,n2
		n1 = L*drandom();
		n2 = L*drandom();
		n3 = L*drandom();
		n4 = L*drandom();
		n.n1=n1; n.n2=n2; n.n3=n3; n.n4=n4;
	
		// New value for the field phi at site n1,n2. phi -> phi+D_phi
		newvalue = phi[n1][n2][n3][n4] + D_Phi*( (2*drandom()-1) + (2*drandom()-1)*I ) ; // or RANDSIGN;

		// Calculate change in action between the new and the old field state
		deltacomplex = deltaS(phi, newvalue, n);
		delta = creal(deltacomplex);

		//printf("deltacomplex: ");
		//PRINT_CMPLX(deltacomplex);
		phi2[n1][n2][n3][n4] = newvalue;
		//s1=Saction(phi);
		//s2=Saction(phi2);
		//printf("Phi s1: ");
		//PRINT_CMPLX(s1);
		//printf("Phi2 s2: ");
		//PRINT_CMPLX(s2);
		//printf("difference: ");
		//difference=s2-s1;
		//PRINT_CMPLX(difference);
		// printf("difference of differences: ");
		// PRINT_CMPLX(deltacomplex-difference);

		//if (cabs(deltacomplex-difference)>10e-7) printf("-------------WRONG DIAFORETIKES TIMES DIAFORAS DRASIS!!!---------------\n");
		
		// Decide whether the new state is to be accepted or not
		if ( (delta <=0 ) || (drandom()<exp(-delta)) )
		{ 	// Accepted!
			phi[n1][n2][n3][n4] = newvalue; 
			acceptedstates++;
			#ifdef VERBOSE_MODE
			printmatrixColorPoint(phi, n1, n2, n3, n4);
			#endif
		} 
		else
		{ 	// Not accepted
			phi2[n1][n2][n3][n4] = phi[n1][n2][n3][n4];
			dropedstates++;
		}

		//printf("Accepted States: %d\nDroped States: %d\n\n", acceptedstates, dropedstates);
		

	}//sweep ends

	if (!silent)
		printf("Acceptance Ratio: %f\n", (1.0*acceptedstates)/(acceptedstates+dropedstates));
}

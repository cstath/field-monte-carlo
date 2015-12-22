/************************  action.c *********************************/
#include "include.h"
#include "action.h"

artype twoxSn(artype [L][L], int n1, int n2);

double Saction(artype phi[L][L] )
{	/* Calculates the action of a field state phi */
	int n1,n2;
	artype sum = 0;

	//printmatrix(phi);	
	
	for(n1=0; n1<L; n1++){
		for(n2=0; n2<L; n2++)
		{
			sum += twoxSn(phi, n1, n2);
		}
	}

	return sum * 0.5;
}

// Calculate the DOUBLE (2X) of the contribution to the action for a field site n1,n2
artype twoxSn(artype phi[L][L], int n1, int n2)
{
	artype sum=0;
	
	// calculating the double of exact Sn

	sum += (2*DIM+M^2)*pwr2(phi[n1][n2]);
	sum += -phi[n1][n2] * ( phi[wrap(n1-1)][wrap(n2)] + phi[wrap(n1+1)][wrap(n2)] + phi[wrap(n1)][wrap(n2-1)] + phi[wrap(n1)][wrap(n2+1)]);

	return sum;
}

// Calculate change in action between the new and the old field state
double deltaS(artype phi[L][L], artype newphi, int n1, int n2)
{	//actually 2*deltaS
	artype sum = 0;

	sum += (2*DIM+M^2)*( pwr2(newphi) - pwr2(phi[wrap(n1)][wrap(n2)]) );
	sum += -2*(newphi - phi[n1][n2])*( phi[wrap(n1-1)][wrap(n2)] + phi[wrap(n1+1)][wrap(n2)] + phi[wrap(n1)][wrap(n2-1)] + phi[wrap(n1)][wrap(n2+1)] );

	return sum * 0.5 ;
}

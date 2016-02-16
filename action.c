/************************  action.c *********************************/
#include "include.h"
#include "fields.h"
#include "action.h"

static artype Sn(artype [L][L][L][L], fieldpos n);

// Bose gas at finite chemical potential
artype Saction(artype phi[L][L][L][L] )
{	/* Calculates the action of a field state phi */
	int n1,n2,n3,n4;
	fieldpos n;
	artype sum = 0;

	//printmatrix(phi);	
	
	for(n1=0; n1<L; n1++){
		for(n2=0; n2<L; n2++){
			for(n3=0; n3<L; n3++){
				for(n4=0; n4<L; n4++)
				{	
					n.n1=n1; n.n2=n2; n.n3=n3; n.n4=n4;
					sum += Sn(phi, n);
				}
			}
		}
	}

	return sum; //* 0.5;
}

// Calculate the contribution to the action for a field site n1,n2
static artype Sn(artype phi[L][L][L][L], fieldpos n)
{	
	artype sum=0;
	
	// calculating the double of exact Sn

	sum += (2*DIM+pwr2(M))*(conj(fval(phi,n,0))*fval(phi,n,0)) + LAMBDA*pwr2( conj(fval(phi,n,0))*fval(phi,n,0) );

	//mexri edw kala, apo dw kai katw to makeleio
	sum += -( conj(fval(phi,n,0)) * fval(phi,n,1) + conj(fval(phi,n,1)) * fval(phi,n,0) );

	sum += -( conj(fval(phi,n,0)) * fval(phi,n,2) + conj(fval(phi,n,2)) * fval(phi,n,0) );

	sum += -( conj(fval(phi,n,0)) * fval(phi,n,3) + conj(fval(phi,n,3)) * fval(phi,n,0) );

	sum += -( conj(fval(phi,n,0)) * exp(-MU) * fval(phi,n,4) + conj(fval(phi,n,4)) * exp(MU) * fval(phi,n,0) );
	//sum += -( conj(phi[n1][n2]) * exp(-MU) * phi[wrap(n1)][wrap(n2+1)] + conj(phi[wrap(n1)][wrap(n2+1)]) * exp(MU) * phi[n1][n2] );

	return sum;
}

// Calculate change in action between the new and the old field state
artype deltaS(artype phi[L][L][L][L], artype newphi, fieldpos n)
{	//actually 2*deltaS
	artype sum = 0;
	int mi;

	sum += (2*DIM+pwr2(M)) * ( conj(newphi)*newphi - conj(fval(phi,n,0))*fval(phi,n,0) );
	sum += LAMBDA * ( pwr2(conj(newphi)*newphi) - pwr2(conj(fval(phi,n,0))*fval(phi,n,0)) );

	//mexri edw kala, apo dw kai katw to makeleio
	for(mi=1;mi<=4;mi++){
		sum += -( conj( newphi-fval(phi,n,0) ) * exp(-MU*krondelta(mi,4)) * fval(phi,n,mi) );
		sum += -( conj( fval(phi,n,mi) ) * exp(MU*krondelta(mi,4)) * (newphi - fval(phi,n,0)) );
	}
	
	for(mi=1;mi<=4;mi++){
		sum += -( conj( fval(phi,n,-mi) ) * exp(-MU*krondelta(mi,4)) * ( newphi - fval(phi,n,0)) );
		sum += -( conj( newphi - fval(phi,n,0) ) * exp(MU*krondelta(mi,4)) * fval(phi,n,-mi) );
	}

	return sum; // * 0.5 ;
}

/************************ action.c ************************/
#include "action.h"

static artype Sn(field *pfield, fieldpos n);

/* Calculates the action of the field state phi */
artype Saction(field *pfield)
{	
	int L = pfield->L;

	int n1,n2,n3,n4;
	fieldpos n;
	artype sum = 0;
	
	for(n1=0; n1<L; n1++){
		for(n2=0; n2<L; n2++){
			for(n3=0; n3<L; n3++){
				for(n4=0; n4<L; n4++)
				{	
					n.n1=n1; n.n2=n2;
					n.n3=n3; n.n4=n4;
					sum += Sn(pfield, n);
				}
			}
		}
	}

	return sum;
}

// Calculate the contribution to the action for a field site n
static artype Sn(field *pfield, fieldpos n)
{	
	int M = pfield->M;
	double MU = pfield->MU;
	double LAMBDA = pfield->LAMBDA;

	artype sum=0;
	int mi;

	sum += (2*DIM+pwr2(M))*(conj(fval(pfield,n,0))*fval(pfield,n,0)); 
	sum += LAMBDA*pwr2( conj(fval(pfield,n,0))*fval(pfield,n,0) );

	for(mi=1;mi<=4;mi++){
		sum -= conj(fval(pfield,n,0)) * exp(-MU*krondelta(mi,4)) * fval(pfield,n,mi) + conj(fval(pfield,n,mi)) * exp(MU*krondelta(mi,4)) * fval(pfield,n,0);
	}

	return sum;
}

// Calculates the change in action between the new and the old field state
artype deltaS(field *pfield, artype newphi, fieldpos n)
{	
	int M = pfield->M;
	double MU = pfield->MU;
	double LAMBDA = pfield->LAMBDA;

	artype sum = 0;
	int mi;

	sum += (2*DIM+pwr2(M)) * ( conj(newphi)*newphi - conj(fval(pfield,n,0))*fval(pfield,n,0) );
	sum += LAMBDA * ( pwr2(conj(newphi)*newphi) - pwr2(conj(fval(pfield,n,0))*fval(pfield,n,0)) );

	for(mi=1;mi<=4;mi++){
		sum -= conj( newphi-fval(pfield,n,0) ) * exp(-MU*krondelta(mi,4)) * fval(pfield,n,mi);
		sum -= conj( fval(pfield,n,mi) ) * exp(MU*krondelta(mi,4)) * (newphi - fval(pfield,n,0));
	}
	
	for(mi=1;mi<=4;mi++){
		sum -= conj( fval(pfield,n,-mi) ) * exp(-MU*krondelta(mi,4)) * ( newphi - fval(pfield,n,0));
		sum -= conj( newphi - fval(pfield,n,0) ) * exp(MU*krondelta(mi,4)) * fval(pfield,n,-mi);
	}

	return sum;
}

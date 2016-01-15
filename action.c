/************************  action.c *********************************/
#include "include.h"
#include "action.h"
#include "fieldmanip.h"

// Bose gas at finite chemical potential
artype Saction(artype phi[L][L][L][L] )
{	/* Calculates the action of a field state phi */
	int n1,n2,n3,n4;
	artype sum = 0;

	//printmatrix(phi);	
	
	for(n1=0; n1<L; n1++){
		for(n2=0; n2<L; n2++){
			for(n3=0; n3<L; n3++){
				for(n4=0; n4<L; n4++)
				{
					sum += Sn(phi, n1, n2, n3, n4);
				}
			}
		}
	}

	return sum; //* 0.5;
}

// Calculate the contribution to the action for a field site n1,n2
static artype Sn(artype phi[L][L][L][L], int n1, int n2, int n3, int n4)
{	
	artype sum=0;
	
	// calculating the double of exact Sn

	sum += (2*DIM+pwr2(M))*(conj(phi[n1][n2][n3][n4])*phi[n1][n2][n3][n4]) + LAMBDA*pwr2( conj(phi[n1][n2][n3][n4])*phi[n1][n2][n3][n4] );

	//mexri edw kala, apo dw kai katw to makeleio
	sum += -( conj(phi[n1][n2][n3][n4]) * phi[wrap(n1+1)][wrap(n2)][wrap(n3)][wrap(n4)] + conj(phi[wrap(n1+1)][wrap(n2)][wrap(n3)][wrap(n4)]) * phi[n1][n2][n3][n4] );

	sum += -( conj(phi[n1][n2][n3][n4]) * phi[wrap(n1)][wrap(n2+1)][wrap(n3)][wrap(n4)] + conj(phi[wrap(n1)][wrap(n2+1)][wrap(n3)][wrap(n4)]) * phi[n1][n2][n3][n4] );

	sum += -( conj(phi[n1][n2][n3][n4]) * phi[wrap(n1)][wrap(n2)][wrap(n3+1)][wrap(n4)] + conj(phi[wrap(n1)][wrap(n2)][wrap(n3+1)][wrap(n4)]) * phi[n1][n2][n3][n4] );

	sum += -( conj(phi[n1][n2][n3][n4]) * exp(-MU) * phi[wrap(n1)][wrap(n2)][wrap(n3)][wrap(n4+1)] + conj(phi[wrap(n1)][wrap(n2)][wrap(n3)][wrap(n4+1)]) * exp(MU) * phi[n1][n2][n3][n4] );
	//sum += -( conj(phi[n1][n2]) * exp(-MU) * phi[wrap(n1)][wrap(n2+1)] + conj(phi[wrap(n1)][wrap(n2+1)]) * exp(MU) * phi[n1][n2] );

	return sum;
}

// Calculate change in action between the new and the old field state
artype deltaS(artype phi[L][L][L][L], artype newphi, int n1, int n2, int n3, int n4)
{	//actually 2*deltaS
	artype sum = 0;
	int mi;

	sum += (2*DIM+pwr2(M)) * ( conj(newphi)*newphi - conj(phi[wrap(n1)][wrap(n2)][wrap(n3)][wrap(n4)])*phi[wrap(n1)][wrap(n2)][wrap(n3)][wrap(n4)] );
	sum += LAMBDA * ( pwr2(conj(newphi)*newphi) - pwr2(conj(phi[wrap(n1)][wrap(n2)][wrap(n3)][wrap(n4)])*phi[wrap(n1)][wrap(n2)][wrap(n3)][wrap(n4)]) );

	//mexri edw kala, apo dw kai katw to makeleio
	for(mi=1;mi<=4;mi++){
		sum += -( conj( newphi-fval(phi,n1,n2,n3,n4,0) ) * exp(-MU*krondelta(mi,4)) * fval(phi,n1,n2,n3,n4,mi) );
		sum += -( conj( fval(phi,n1,n2,n3,n4,mi) ) * exp(MU*krondelta(mi,4)) * (newphi - fval(phi,n1,n2,n3,n4,0)) );
	}
	
	for(mi=1;mi<=4;mi++){
		sum += -( conj( fval(phi,n1,n2,n3,n4,-mi) ) * exp(-MU*krondelta(mi,4)) * ( newphi - fval(phi,n1,n2,n3,n4,0)) );
		sum += -( conj( newphi - fval(phi,n1,n2,n3,n4,0) ) * exp(MU*krondelta(mi,4)) * fval(phi,n1,n2,n3,n4,-mi) );
	}

	return sum; // * 0.5 ;
}

/* 	
	return the value of a field by offset of 1 at the mi direction from the position (n1,n2)
	negative vaules of mi indicate negative offset
*/
static artype fval(artype phi[L][L][L][L], int n1, int n2, int n3, int n4, int mi)
{	int sign;

	sign = SIGN(mi);
	switch (abs(mi)) {
		case 1:
			return phi[wrap(n1+sign)][wrap(n2)][wrap(n3)][wrap(n4)];
			break;
		case 2:
			return phi[wrap(n1)][wrap(n2+sign)][wrap(n3)][wrap(n4)];
			break;
		case 3:
			return phi[wrap(n1)][wrap(n2)][wrap(n3+sign)][wrap(n4)];
			break;
		case 4:
			return phi[wrap(n1)][wrap(n2)][wrap(n3)][wrap(n4+sign)];
			break;
		case 0:
			return phi[wrap(n1)][wrap(n2)][wrap(n3)][wrap(n4)];
			break;
		default :
			fprintf(stderr, "fval function argument mi out of bound");
			exit(1);
			return 0;
	}

}
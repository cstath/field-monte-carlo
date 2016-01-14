/************************  action.c *********************************/
#include "include.h"
#include "action.h"

// Bose gas at finite chemical potential
artype Saction(artype phi[L][L] )
{	/* Calculates the action of a field state phi */
	int n1,n2;
	artype sum = 0;

	//printmatrix(phi);	
	
	for(n1=0; n1<L; n1++){
		for(n2=0; n2<L; n2++)
		{
			sum += Sn(phi, n1, n2);
		}
	}

	return sum; //* 0.5;
}

// Calculate the contribution to the action for a field site n1,n2
static artype Sn(artype phi[L][L], int n1, int n2)
{	
	artype sum=0;
	
	// calculating the double of exact Sn

	sum += (2*DIM+pwr2(M))*(conj(phi[n1][n2])*phi[n1][n2]) + LAMBDA*pwr2( conj(phi[n1][n2])*phi[n1][n2] );

	//mexri edw kala, apo dw kai katw to makeleio
	sum += -( conj(phi[n1][n2]) * phi[wrap(n1+1)][wrap(n2)] + conj(phi[wrap(n1+1)][wrap(n2)]) * phi[n1][n2] );
	sum += -( conj(phi[n1][n2]) * exp(-MU) * phi[wrap(n1)][wrap(n2+1)] + conj(phi[wrap(n1)][wrap(n2+1)]) * exp(MU) * phi[n1][n2] );
	//sum += -( conj(phi[n1][n2]) * exp(-MU) * phi[wrap(n1)][wrap(n2+1)] + conj(phi[wrap(n1)][wrap(n2+1)]) * exp(MU) * phi[n1][n2] );

	return sum;
}

// Calculate change in action between the new and the old field state
artype deltaS(artype phi[L][L], artype newphi, int n1, int n2)
{	//actually 2*deltaS
	artype sum = 0;
	int mi;

	sum += (2*DIM+pwr2(M)) * ( conj(newphi)*newphi - conj(phi[wrap(n1)][wrap(n2)])*phi[wrap(n1)][wrap(n2)] );
	sum += LAMBDA * ( pwr2(conj(newphi)*newphi) - pwr2(conj(phi[wrap(n1)][wrap(n2)])*phi[wrap(n1)][wrap(n2)]) );

	//mexri edw kala, apo dw kai katw to makeleio
	for(mi=1;mi<=2;mi++){
		sum += -( conj( newphi-fval(phi,n1,n2,0) ) * exp(-MU*krondelta(mi,2)) * fval(phi,n1,n2,mi) );
		sum += -( conj( fval(phi,n1,n2,mi) ) * exp(MU*krondelta(mi,2)) * (newphi - fval(phi,n1,n2,0)) );
	}
	
	for(mi=1;mi<=2;mi++){
		sum += -( conj( fval(phi,n1,n2,-mi) ) * exp(-MU*krondelta(mi,2)) * ( newphi - fval(phi,n1,n2,0)) );
		sum += -( conj( newphi - fval(phi,n1,n2,0) ) * exp(MU*krondelta(mi,2)) * fval(phi,n1,n2,-mi) );
	}

	return sum; // * 0.5 ;
}

/* 	
	return the value of a field by offset of 1 at the mi direction from the position (n1,n2)
	negative vaules of mi indicate negative offset
*/
static artype fval(artype phi[L][L], int n1, int n2, int mi)
{	int sign;

	sign = SIGN(mi);
	switch (abs(mi)) {
		case 1:
			return phi[wrap(n1+sign)][wrap(n2)];
			break;
		case 2:
			return phi[wrap(n1)][wrap(n2+sign)];
			break;
		case 0:
			return phi[wrap(n1)][wrap(n2)];
			break;
		default :
			fprintf(stderr, "fval function argument mi out of bound");
			exit(1);
			return 0;
	}

}


// artype deltaS(artype phi[L][L], artype newphi, int n1, int n2)
// {	//actually 2*deltaS
// 	artype sum = 0;

// 	sum += (2*DIM+pwr2(M)) * ( conj(newphi)*newphi - conj(phi[wrap(n1)][wrap(n2)])*phi[wrap(n1)][wrap(n2)] );
// 	sum += LAMBDA * ( pwr2(conj(newphi)*newphi) - pwr2(conj(phi[wrap(n1)][wrap(n2)])*phi[wrap(n1)][wrap(n2)]) );

// 	//mexri edw kala, apo dw kai katw to makeleio

// 	sum += -( conj( newphi-phi[wrap(n1)][wrap(n2)] ) * exp(-MU*0) * phi[wrap(n1+1)][wrap(n2)] );
// 	sum += -( conj( phi[wrap(n1+1)][wrap(n2)] ) * exp(MU*0) * (newphi - phi[wrap(n1)][wrap(n2)]) );

// 	sum += -( conj(newphi - phi[wrap(n1)][wrap(n2)]) * exp(-MU*1) * phi[wrap(n1)][wrap(n2+1)] );
// 	sum += -( conj(phi[wrap(n1)][wrap(n2+1)]) * exp(MU*1) * (newphi - phi[wrap(n1)][wrap(n2)]) );
// 	//
// 	sum += -( conj(phi[wrap(n1-1)][wrap(n2)]) * exp(-MU*0) * (newphi - phi[wrap(n1)][wrap(n2)]) );
// 	sum += -( conj(newphi - phi[wrap(n1)][wrap(n2)]) * exp(MU*0) * (phi[wrap(n1-1)][wrap(n2)]) );

// 	sum += -( conj(phi[wrap(n1)][wrap(n2-1)]) * exp(-MU*1) * (newphi - phi[wrap(n1)][wrap(n2)]) );
// 	sum += -( conj(newphi - phi[wrap(n1)][wrap(n2)]) * exp(MU*1) * phi[wrap(n1)][wrap(n2-1)] );

// 	return sum; // * 0.5 ;
// }
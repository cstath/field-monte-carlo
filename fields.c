/************************ fields.c ************************/
#include "fields.h"

// Create a Field on a 4D lattice of dimensional size L, mass M,
// coupling constant LAMBDA and chemical potential MU.
field create_field(int L, double M, double LAMBDA, double MU) {

	field scalarfield;

	scalarfield.L = L;
	scalarfield.N = L*L*L*L;
	scalarfield.M = M;
	scalarfield.LAMBDA = LAMBDA;
	scalarfield.MU = MU;

	int n1, n2, n3, n4;

	artype **** lattice;

	// Allocate memmory for the 4D lattice and initialize with zeros
	lattice = malloc( L * sizeof(artype ***));
	for (n1 = 0; n1 < L; n1++) {
		lattice[n1] = malloc( L * sizeof(artype **));
		for (n2 = 0; n2 < L; n2++) {
			lattice[n1][n2] = malloc( L * sizeof(artype *));
			for (n3 = 0; n3 < L; n3++) {
				lattice[n1][n2][n3] = malloc( L * sizeof(artype));
				for (n4 = 0; n4 < L; n4++) {
					lattice[n1][n2][n3][n4] = 0;
				}
			}
		}
	}

	scalarfield.lattice = lattice;

	return scalarfield;
}

// Destroy a Field by freeing the allocated memory of the 4D lattice
int destroy_field( field *afield) {

	int L = afield->L;
	artype **** lattice = afield->lattice;

	int n1, n2, n3;

	for (n1 = 0; n1 < L; n1++) {
		for (n2 = 0; n2 < L; n2++) {
			for (n3 = 0; n3 < L; n3++) {
				free( lattice[n1][n2][n3] );
			}
			free( lattice[n1][n2] );
		}
		free( lattice[n1] );
	}
	free( lattice );

	return 0;
}

//	Return the value of a field by offset of 1 in the mi direction at the
//	position n. negative vaules of mi indicate negative offset
artype fval(field *afield, fieldpos n, int mi)
{	int sign;

	int L = afield->L;
	artype ****fieldlat = (artype ****) afield->lattice;

	sign = SIGN(mi);
	switch (abs(mi)) {
	case 1:
		return fieldlat[wrap(n.n1 + sign,L)][n.n2][n.n3][n.n4];
		break;
	case 2:
		return fieldlat[n.n1][wrap(n.n2 + sign,L)][n.n3][n.n4];
		break;
	case 3:
		return fieldlat[n.n1][n.n2][wrap(n.n3 + sign,L)][n.n4];
		break;
	case 4:
		return fieldlat[n.n1][n.n2][n.n3][wrap(n.n4 + sign, L)];
		break;
	case 0:
		return fieldlat[n.n1][n.n2][n.n3][n.n4];
		break;
	default :
		fprintf(stderr, "fval function argument mi out of bounds");
		exit(1);
		return 0;
	}

}

// Periodical boundary conditions
int wrap(int x, int L)
{
	return ( (((x) % L) + L) % L );
}
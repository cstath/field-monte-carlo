/************************ fields.h ************************/
#ifndef FIELDS_H
#define FIELDS_H

#include "common.h"

#define DIM 4	// Number of Euclidian dimensions

#define pwr2(x) ( (x)*(x) )
#define SIGN(x) (((x) > 0) - ((x) < 0))

// type of the field - complex scalar
typedef double complex artype;

// this structure hold a field's state on the lattice
// together with its properties
typedef struct field_structure {

	int L;		// Dimensions size of the lattice
	int N;		// Number of total lattice sites
	double M;		// This is the mass of the field
	double LAMBDA;	// Coupling constant Lambda
	double MU;	// Chemical Potential

	artype **** lattice;	// Pointer to a 4-D lattice array

} field;

// Grouping of a site's position on the 4-D field lattice
typedef struct field_position {

	int n1, n2, n3, n4;

} fieldpos;

// Create a Field on a 4D lattice of dimensional size L, mass M,
// coupling constant LAMBDA and chemical potential MU.
field create_field(int L, double M, double LAMBDA, double MU);

// Destroy a Field by freeing the allocated memory of the 4D lattice
int destroy_field( field *afield);

//	Return the value of a field by offset of 1 in the mi direction at the
//	position n. negative vaules of mi indicate negative offset
artype fval(field *scalarfield, fieldpos n, int mi);

// Periodical boundary conditions
int wrap(int x, int L);

#endif
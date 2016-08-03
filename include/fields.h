/************************ fields.h ************************/
#ifndef FIELDS_H
#define FIELDS_H

/**
 * @file fields.h
 * Contains the structures and basic functions for a field
 */

#include "common.h"

#define DIM 4	// Number of Euclidian dimensions

#define pwr2(x) ( (x)*(x) )
#define SIGN(x) (((x) > 0) - ((x) < 0))

/** The type of the field - a complex scalar */
typedef double complex artype;

/** A field's data structure */
typedef struct field_structure {

	int L;		///< Dimensions size of the lattice
	int N;		///< Number of total lattice sites
	double M;		///< This is the mass of the field
	double LAMBDA;	///< Coupling constant Lambda
	double MU;	///< Chemical Potential
	
	artype **** lattice; ///< Pointer to a 4-D array holding the state of the field on the lattice 

} field;

/** Grouping of a site's position on the 4-D field lattice 
 *	@see field */
typedef struct field_position {

	int n1; ///< Coordinate 1 of a field's site on the 4-D lattice
	int n2; ///< Coordinate 2 of a field's site on the 4-D lattice
	int n3; ///< Coordinate 3 of a field's site on the 4-D lattice
	int n4; ///< Coordinate 4 of a field's site on the 4-D lattice

} fieldpos;

/**	Create a Field on a 4D lattice with the specified parameters
 *	@see field
 *	@see destroy_field()
 *	@returns The structure of the field */
field create_field(int L, double M, double LAMBDA, double MU);

/**	Destroy the field by freeing the allocated memory of the lattice array
 *	@see field 
 *	@see create_field()
 *	@param pfield a pointer to a field structure */
void destroy_field( field *pfield);

/**	Return the value of the field on the 4D lattice, by offset of 1 from the 
 * 	position n in the mi direction
 *	@see field 
 *	@see fieldpos
 *	@param pfield a pointer to a field structure 
 *	@param n a base position on the lattice 
 *	@param mi the direction at which the offseting takes place from the base n. 
 *	Negative values of mi indicate negative offset 
 *	@returns The value of the field at position n+1 (in the mi direction) */
artype fval(field *pfield, fieldpos n, int mi);

/** Modulo function for imposing Periodical Boundary Conditions 
 *	@param x the value of the coordinate on a lattice (dividend) 
 *	@param L the dimension size of the lattice (divisor) 
 *	@returns x%L taking care for the negative values */
int wrap(int x, int L);

#endif
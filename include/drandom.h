/************************ met.h ************************/
#ifndef DRANDOM_H
#define DRANDOM_H

/**
 * @file drandom.h
 * Contains the declerations for the random number generator
 */

extern long seed;	//< the seed for the random number generator

/**	generate a random number in [0,1)
 *	@see seed
 *	@returns A real random numbern in [0,1)*/
double drandom();

#endif
/************************ measure.h ************************/
#ifndef MEASURE_H
#define MEASURE_H

/**
 * @file measure.h
 * Contains the functions for performing measurements on a field
 */

#include "common.h"
#include "fields.h"
#include "action.h"

/** Prints out all the measurements on the scalar field state for the
 *	Phase Quenched Model
 *	@see field
 *	@param afield a field structure */
void measure(field afield);

/** Calculates the average value of the squared field 
 *	for the Phase Quenched Model
 *	@see field
 *	@param afield a field structure 
 *	@returns The average value of the squared field */
double AvgFieldSquared(field afield);

/** Returns the imaginary part of the field's complex Action
 *	for the Phase Quenched Model
 *	@see field
 *	@param afield a field structure 
 *	@returns the imaginary part of the field's Action */
double ImgAction(field afield);

/** Returns the average particle density for the Phase Quenched Model
 *	@see field
 *	@param afield a field structure 
 *	@returns The average particle density */
artype AvgParticleDensityComplex(field afield);

#endif
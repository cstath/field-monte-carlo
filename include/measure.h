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
 *	Phase Quenched theory 
 *	@see field
 *	@param afield a field structure */
void measure(field afield);

#endif
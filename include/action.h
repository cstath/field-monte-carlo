/************************ action.h ************************/
#ifndef ACTION_H
#define ACTION_H

/**
 * @file action.h
 * Contains the functions for the action of a field
 */

#include "common.h"
#include "fields.h"

#define krondelta(x,y) ( ((x)==(y)) ? (1) : (0) )

/**	Calculates the action over the field state
 *	@see field
 *	@param pfield pointer to a field structure
 *	@returns The value of the action of the field state */
artype Saction(field *pfield);

/**	Calculates the difference in action between the new and the old field state
 *	@see artype
 *	@see field
 *	@see fieldpos
 *	@param pfield pointer to a field structure
 *	@param newphi newvalue of the field at position n
 *	@param n position on the lattice where the field changes
 *	@returns The difference in action between the new and the old field state */
artype deltaS(field *pfield, artype newphi, fieldpos n);

#endif
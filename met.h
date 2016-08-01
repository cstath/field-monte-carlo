/************************ met.h ************************/
#ifndef MET_H
#define MET_H

#include "common.h"
#include "drandom.h"
#include "fields.h"
#include "action.h"

#define D_Phi 0.3	// Delta_Phi is the maximum change in the field between 
					// consecutive states - tune this to get a good acceptance ratio ~0.7

// Performs a metropolis algorithm sweep on the given field
void met(field *pfield);

#endif
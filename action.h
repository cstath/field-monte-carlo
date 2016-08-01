/************************ action.h ************************/
#ifndef ACTION_H
#define ACTION_H

#include "common.h"
#include "fields.h"

#define krondelta(x,y) ( ((x)==(y)) ? (1) : (0) )

// Calculates the action of the field state phi 
artype Saction(field *pfield);

// Calculates the difference in action between the new and the old field state
artype deltaS(field *pfield, artype newphi, fieldpos n);

#endif
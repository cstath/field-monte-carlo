/********* action.h *********/
#ifndef ACTION_H
#define ACTION_H

#define krondelta(x,y) ( ((x)==(y)) ? (1) : (0) )

artype Saction(artype phi[L][L][L][L]);
artype deltaS(artype phi[L][L][L][L], artype newphi, fieldpos n);

#endif
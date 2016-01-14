/********* action.h *********/
#ifndef ACTION_H
#define ACTION_H

#define DIM 2
#define LAMBDA 1
#define MU 1

#define krondelta(x,y) ( ((x)==(y)) ? (1) : (0) )
#define wrap(x) ((((x) % L) + L) % L)

artype Saction(artype phi[L][L]);
artype deltaS(artype phi[L][L], artype newphi, int n1, int n2);

static artype Sn(artype [L][L], int n1, int n2);
static artype fval(artype phi[L][L], int n1, int n2, int mi);

#endif
/********* action.h *********/
#ifndef ACTION_H
#define ACTION_H

#define DIM 2

double Saction(artype phi[L][L]);
double deltaS(artype phi[L][L], artype newphi, int n1, int n2);

#endif
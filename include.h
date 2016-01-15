/************************** include.h ********************************/
#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <unistd.h>

#define VERBOSE_MODE

#define L 6
#define N (L*L*L*L)
#define M 1
#define D_Phi 0.3
//#define artype double // int/float/double , for int check RANDSIGN also.


#define pwr2(x) ( (x)*(x) )
#define SIGN(x) (((x) > 0) - ((x) < 0))
#define RANDSIGN ( (drandom() > 0.5) ? (1) : (-1) )

typedef double complex artype;

double beta;

artype phi2[L][L][L][L];

double drandom();
long seed;
void init(int start, artype phi[L][L][L][L]); 
void met(artype phi[L][L][L][L]); 
void measure(artype phi[L][L][L][L]);

#endif
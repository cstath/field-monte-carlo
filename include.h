/************************** include.h ********************************/
#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <unistd.h>

#define L 4
#define N (L*L*L*L)

//#define VERBOSE_MODE

//#define artype double // int/float/double , for int check RANDSIGN also.

//#define RANDSIGN ( (drandom() > 0.5) ? (1) : (-1) )

typedef double complex artype;

int silent;
int start;
int nsweep, nmeasurement;
long seed;

artype phi2[L][L][L][L];

double drandom();
//long seed;
void init(int start, artype phi[L][L][L][L]); 
void met(artype phi[L][L][L][L]); 
void measure(artype phi[L][L][L][L]);

#endif
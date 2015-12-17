/************************** include.h ********************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define L 12
#define N (L*L)
#define M 1
#define DIM 2
#define D_Phi 1
#define artype double // int/float/double , for int check RANDSIGN also.

#define wrap(x) (((x % L) + L) % L)
#define pwr2(x) ((x)*(x))
#define sign(x) ((x > 0) - (x < 0))
#define RANDSIGN ( (drandom() > 0.5) ? (1) : (-1) )

artype phi[L][L];
//int phi2[L][L]; 	// remove when done
int acceptedstates, dropedstates;
double beta;
//double prob[5];

//int     E(), M();
double drandom();
long seed;
void init(int start, artype phi[L][L]), met(artype phi[L][L]), measure(artype phi[L][L]);
double AvgField(artype phi[L][L]);

double Saction(artype phi[L][L]);
artype twoxSn(artype phi[L][L], int n1, int n2);
double deltaS(artype phi[L][L], artype newphi, int n1, int n2);

void printmatrix(artype phi[L][L]);
void printmatrixColor(artype phi[L][L], int n1, int n2);
char * color(artype phi);

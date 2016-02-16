/************************** fields.h ********************************/

#ifndef FIELDS_H
#define FIELDS_H

#define M 1
#define DIM 4
#define LAMBDA 1
//#define MU 1.5
#define D_Phi 0.3

#define pwr2(x) ( (x)*(x) )
#define SIGN(x) (((x) > 0) - ((x) < 0))
#define wrap(x) ((((x) % L) + L) % L)

typedef struct field_position {

	int n1, n2, n3, n4;

} fieldpos;

double MU;

artype fval(artype phi[L][L][L][L], fieldpos n, int mi);

#endif
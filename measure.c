/************************   measure.c ******************************/
#include "include.h"

static artype AvgField(artype [L][L]);
static double AvgFieldSquared(artype [L][L]);

void measure(artype phi[L][L]){
	/* Prints out all the measurements on the scalar field state */
	artype avg=AvgField(phi);
	printf("Average Phi= %f + %fi \t", creal(avg), cimag(avg) );
	printf("Average Phi^2=%f\n", AvgFieldSquared(phi));
}

static artype AvgField(artype phi[L][L]){
	/* Returns the average value of the scalar field */
	int n1,n2;
	artype sum=0;

	for(n1=0;n1<L;n1++){
		for(n2=0;n2<L;n2++){
			sum += phi[n1][n2];
		}
	}

	return (sum/N);
}

static double AvgFieldSquared(artype phi[L][L]){
	/* Returns the average value of the squared scalar field */
	int n1,n2;
	double sum=0;

	for(n1=0;n1<L;n1++){
		for(n2=0;n2<L;n2++){
			sum += pwr2(cabs(phi[n1][n2]));
		}
	}

	return (sum/N);
}

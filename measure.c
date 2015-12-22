/************************   measure.c ******************************/
#include "include.h"

double AvgField(artype [L][L]);
double AvgFieldSquared(artype [L][L]);

void measure(artype phi[L][L]){
	/* Prints out all the measurements on the scalar field state */
	printf("Average Phi=%f \t", AvgField(phi));
	printf("Average Phi^2=%f\n", AvgFieldSquared(phi));
}

double AvgField(artype phi[L][L]){
	/* Returns the average value of the scalar field */
	int n1,n2;
	artype sum=0;

	for(n1=0;n1<L;n1++){
		for(n2=0;n2<L;n2++){
			sum += phi[n1][n2];
		}
	}

	return ((double)sum)/N;
}

double AvgFieldSquared(artype phi[L][L]){
	/* Returns the average value of the squared scalar field */
	int n1,n2;
	artype sum=0;

	for(n1=0;n1<L;n1++){
		for(n2=0;n2<L;n2++){
			sum += pwr2(phi[n1][n2]);
		}
	}

	return ((double)sum)/N;
}

/*
int M(){
  int i,m;
  m=0;
  for(i=0;i<N;i++) m+=s[i];
  return m;
} */

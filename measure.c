/************************   measure.c ******************************/
#include "include.h"

void measure(artype phi[L][L]){
	printf("Average Phi=%f\n", AvgField(phi));
}

double AvgField(artype phi[L][L]){
	
	int n1,n2;
	artype sum=0;

	for(n1=0;n1<L;n1++){
		for(n2=0;n2<L;n2++){
			sum += phi[n1][n2];
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

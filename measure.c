/************************   measure.c ******************************/
#include "include.h"
#include "fields.h"

//static artype AvgField(artype [L][L][L][L]);
static double AvgFieldSquared(artype [L][L][L][L]);
static double AvgParticleDensity(artype phi[L][L][L][L]);

void measure(artype phi[L][L][L][L]){
	/* Prints out all the measurements on the scalar field state */
	//artype avg=AvgParticleDensity(phi);
	//printf("Average n= %f + %fi \t", creal(avg), cimag(avg) );
	//printf("Average Phi^2=%f\n", AvgFieldSquared(phi));
	if (!silent)
		printf("Average Phi^2=%f , Average n=%f\n", AvgFieldSquared(phi), AvgParticleDensity(phi));
	else
		printf("%f %f\n", AvgFieldSquared(phi), AvgParticleDensity(phi));
}


static double AvgFieldSquared(artype phi[L][L][L][L]){
	/* Returns the average value of the squared scalar field |Φ|^2 */
	int n1,n2,n3,n4;
	double sum=0;

	for(n1=0;n1<L;n1++){
		for(n2=0;n2<L;n2++){
			for(n3=0;n3<L;n3++){
				for(n4=0;n4<L;n4++){
					sum += pwr2(cabs(phi[n1][n2][n3][n4]));
				}
			}
		}
	}

	return (sum/N);
}

static double AvgParticleDensity(artype phi[L][L][L][L]){
	/* Returns the average value of the particle density <n> */
	int n1,n2,n3,n4;
	fieldpos n;
	double sum=0;

	for(n1=0;n1<L;n1++){
		for(n2=0;n2<L;n2++){
			for(n3=0;n3<L;n3++){
				for(n4=0;n4<L;n4++){
					n.n1=n1; n.n2=n2; n.n3=n3; n.n4=n4;
					sum += 2 * sinh(MU) * ( creal(fval(phi,n,0))*creal(fval(phi,n,4)) + cimag(fval(phi,n,0))*cimag(fval(phi,n,4)) ); // afto pou leei to paper
				}
			}
		}
	}

	return (sum/N);
}

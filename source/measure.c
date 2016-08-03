/************************ measure.c ************************/
#include "measure.h"

// Prints out all the measurements on the scalar field state for the Phase Quenched theory
void measure(field afield) {

	artype temp = AvgParticleDensityComplex(afield);

	if (!silent) {
		printf("Average Phi^2_pq=%f  ", AvgFieldSquared(afield) );
		printf("Average n_pq=%f%+fi  Img{S}=%f", creal(temp), cimag(temp), ImgAction(afield) );
		printf("\n");
	}
	else {
		printf("%.8f ", AvgFieldSquared(afield));
		printf("%.8f%+.8fi %.8f ", creal(temp), cimag(temp), ImgAction(afield) );
		printf("\n");
	}

}

// Returns the average value of the squared scalar field |Phi|^2_pq
double AvgFieldSquared(field afield) {

	int n1, n2, n3, n4;
	double sum = 0;

	int L = afield.L;
	int N = afield.N;
	artype **** fieldlat = (artype ****) afield.lattice;

	for (n1 = 0; n1 < L; n1++) {
		for (n2 = 0; n2 < L; n2++) {
			for (n3 = 0; n3 < L; n3++) {
				for (n4 = 0; n4 < L; n4++) {
					sum += pwr2(cabs(fieldlat[n1][n2][n3][n4]));
				}
			}
		}
	}

	return (sum / N);
}

// Returns the imaginary part of the complex Action S
double ImgAction(field afield) {
	return cimag(Saction(&afield));
}

// Returns the average value of the particle density <n>_pq
artype AvgParticleDensityComplex(field afield) {

	int L = afield.L;
	int N = afield.N;
	double MU = afield.MU;

	int n1, n2, n3, n4;
	fieldpos n;
	artype sum = 0;

	field * pfield = &afield; // pointer to the field structure

	for (n1 = 0; n1 < L; n1++) {
		for (n2 = 0; n2 < L; n2++) {
			for (n3 = 0; n3 < L; n3++) {
				for (n4 = 0; n4 < L; n4++) {
					n.n1 = n1; n.n2 = n2; n.n3 = n3; n.n4 = n4;
					sum += ( conj(fval(pfield, n, 4)) * exp(MU) * fval(pfield, n, 0)
					         - conj(fval(pfield, n, 0)) * exp(-MU) * fval(pfield, n, 4) );
				}
			}
		}
	}

	return (sum / N);
}
/************************   printmatrix.c ********************************/
#include "include.h"
#include "printmatrix.h"

#define PRINT_CMPLX(x) printf("%5.1f%+.1fi", creal(x), cimag(x))
#define PRINT_CMPLX_COLOR(c,x) printf("%s%5.1f%+.1fi%s", c, creal(x), cimag(x), RESET)
#define PRINT_CMPLX_COLOR_AUTO(x) printf("%s%5.1f%s%+.1fi%s", color(creal(x)), creal(x), color(cimag(x)), cimag(x), RESET)

char * color(double phi);

void printmatrix(artype phi[L][L])
{	/* Prints out the field state and sleeps 1 sec */
	int n1,n2;
	printf("Field State:\n");
	for(n1=0; n1<L;n1++){
		for(n2=0; n2<L; n2++){
			PRINT_CMPLX(phi[n1][n2]);
		}
		printf("\n\n");
	}
	sleep(1);
}

void printmatrixColor(artype phi[L][L])
{	/* Prints out the field state in color mode and sleeps 1 sec */
	int n1,n2;
	printf("Field State:\n");
	for(n1=0; n1<L;n1++){
		for(n2=0; n2<L; n2++){
			PRINT_CMPLX_COLOR( color(phi[n1][n2]), phi[n1][n2] );
		}
		printf("\n\n");
	}
	sleep(1);
}

void printmatrixColorPoint(artype phi[L][L], int n1in, int n2in)
{	/* Prints out the field state in color mode redening a specific point */
	int n1,n2;
	printf("Field State:\n");
	for(n1=0; n1<L;n1++){
		for(n2=0; n2<L; n2++){
			if( (n1==n1in) && (n2==n2in) )
				PRINT_CMPLX_COLOR( KRED, phi[n1][n2] );
			else PRINT_CMPLX_COLOR_AUTO( phi[n1][n2] );
		}
		printf("\n\n");
	}
	sleep(1);
}

char * color(double phi){
	/* Sets the color in accordance to the field's value */
	if ((phi)<(-2*COLOR_SCALE*D_Phi)) { return (KYEL); }
	else if (phi < -COLOR_SCALE*D_Phi) { return (KGRN); }
	else if (phi < COLOR_SCALE*D_Phi) { return (RESET); }
	else if (phi < 2*COLOR_SCALE*D_Phi) { return (KCYN); }
	else { return (KMAG); }
}

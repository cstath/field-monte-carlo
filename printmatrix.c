/************************   printmatrix.c ********************************/
#include "include.h"
#include "printmatrix.h"

char * color(artype phi);

void printmatrix(artype phi[L][L])
{	/* Prints out the field state and sleeps 1 sec */
	int n1,n2;
	printf("Field State:\n");
	for(n1=0; n1<L;n1++){
		for(n2=0; n2<L; n2++){
			printf("%5d", (int) phi[n1][n2]);
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
			printf("%s%5.1f%s", color(phi[n1][n2]), phi[n1][n2], RESET);;
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
				printf("%s%5.1f%s", KRED, phi[n1][n2], RESET);
			else printf("%s%5.1f%s", color(phi[n1][n2]), phi[n1][n2], RESET);;
		}
		printf("\n\n");
	}
	sleep(1);
}

char * color(artype phi){
	/* Sets the color in accordance to the field's value */
	if (phi<(-2*COLOR_SCALE*D_Phi)) { return (KYEL); }
	else if (phi < -COLOR_SCALE*D_Phi) { return (KGRN); }
	else if (phi < COLOR_SCALE*D_Phi) { return (RESET); }
	else if (phi < 2*COLOR_SCALE*D_Phi) { return (KCYN); }
	else { return (KMAG); }
}




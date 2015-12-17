/************************   printmatrix.c ********************************/
#include "include.h"

//colors
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

#define COLOR_SCALE 0.3


void printmatrix(artype phi[L][L])
{
	int n1,n2;
	printf("Field State:\n");
	for(n1=0; n1<L;n1++){
		for(n2=0; n2<L; n2++){
			printf("%5d", (int) phi[n1][n2]);
		}
		printf("\n\n");
	}
}

void printmatrixColor(artype phi[L][L], int n1in, int n2in)
{
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
	
	if (phi<(-2*COLOR_SCALE*D_Phi)) { return (KYEL); }
	else if (phi < -COLOR_SCALE*D_Phi) { return (KGRN); }
	else if (phi < COLOR_SCALE*D_Phi) { return (RESET); }
	else if (phi < 2*COLOR_SCALE*D_Phi) { return (KCYN); }
	else { return (KMAG); }
}




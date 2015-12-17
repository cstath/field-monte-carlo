/************************   init.c ********************************/
#include "include.h"

/* start= 0  cold
          1  hot  */
void init( int start, artype phi[L][L]){
	int n1,n2;
	/*Initialize probabilities:*/
	//for(i=2;i<5;i+=2) prob[i] = exp(-2*beta*i);
	/*Initial configuration:*/
	switch(start){
	case 0:/*cold start*/
	    for(n1=0;n1<L;n1++){
			for(n2=0;n2<L;n2++){
				phi[n1][n2] = 0;
				//phi2[n1][n2] = 0;//just for test purpuses. remove when done
			}
		} 	
	    break;
	default:
		printf("start= %d not valid. Exiting....\n",start);
		exit(1);
		break;
	}
}

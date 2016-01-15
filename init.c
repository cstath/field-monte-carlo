/************************   init.c ********************************/
#include "include.h"

#define HOTSCALE 5

/* start= 0  cold
          1  hot  */
void init( int start, artype phi[L][L][L][L]){
	int n1,n2,n3,n4;
	printf("Initial state (Cold 0 / Hot 1) : %d\n", start );
	/*Initial configuration:*/
	switch(start){
	case 0:/*cold start*/
		for(n1=0;n1<L;n1++){
			for(n2=0;n2<L;n2++){
				for(n3=0;n3<L;n3++){
					for(n4=0;n4<L;n4++){
						phi[n1][n2][n3][n4] = 0;
						phi2[n1][n2][n3][n4] = 0;//just for test purpuses. remove when done
					}	
				}
			}
		}
		break;
	case 1:/*hot start*/
		for(n1=0;n1<L;n1++){
			for(n2=0;n2<L;n2++){
				for(n3=0;n3<L;n3++){
					for(n4=0;n4<L;n4++){
						phi[n1][n2][n3][n4] = HOTSCALE*(2*drandom()-1) + HOTSCALE*(2*drandom()-1)*I ;
						phi2[n1][n2][n3][n4] = phi[n1][n2][n3][n4];//phi2[n1][n2] = 0;//just for test purpuses. remove when done
					}
				}
			}
		} 	
		break;
	default:
		printf("start= %d not valid. Exiting....\n",start);
		exit(1);
		break;
	}
}

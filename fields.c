/************************** fields.c ********************************/

#include "include.h"
#include "fields.h"
/* 	
	return the value of a field by offset of 1 at the mi direction from the position (n1,n2)
	negative vaules of mi indicate negative offset
*/
artype fval(artype phi[L][L][L][L], fieldpos n, int mi)
{	int sign;

	sign = SIGN(mi);
	switch (abs(mi)) {
		case 1:
			return phi[wrap(n.n1+sign)][wrap(n.n2)][wrap(n.n3)][wrap(n.n4)];
			break;
		case 2:
			return phi[wrap(n.n1)][wrap(n.n2+sign)][wrap(n.n3)][wrap(n.n4)];
			break;
		case 3:
			return phi[wrap(n.n1)][wrap(n.n2)][wrap(n.n3+sign)][wrap(n.n4)];
			break;
		case 4:
			return phi[wrap(n.n1)][wrap(n.n2)][wrap(n.n3)][wrap(n.n4+sign)];
			break;
		case 0:
			return phi[wrap(n.n1)][wrap(n.n2)][wrap(n.n3)][wrap(n.n4)];
			break;
		default :
			fprintf(stderr, "fval function argument mi out of bound");
			exit(1);
			return 0;
	}

}
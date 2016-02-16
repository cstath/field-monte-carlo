/********* printmatrix.h *********/
#ifndef PRINTMATRIX_H
#define PRINTMATRIX_H
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

/* prototypes */
void printmatrix(artype phi[L][L][L][L]);
// void printmatrixColor(artype phi[L][L][L][L]);
void printmatrixColorPoint(artype phi[L][L][L][L], int n1, int n2, int n3, int n4);

#endif
/************************  urandom.c *****************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
int fd_ur;
double rmax;
void init_random(){
  rmax   = 1.0/((double) ULONG_MAX);
  fd_ur  = open("/dev/urandom", O_RDONLY);
}
double drandom(){
  ulong  ur;
  double rr;
  read(fd_ur,&ur,sizeof(ulong));
  rr = ((double) ur) * rmax ;
  if( rr <  0.0) drandom(); //pathological cases-should be rare...
  if( rr >= 1.0) drandom();
  return rr;
}

/** main() for testing */
/*
#include <stdio.h>
int main(int argc, char **argv){
  int i;
  int Nrand=100000;
  init_random();
  if(argc>1) Nrand = atoi(argv[1]);
  //  printf("# Initialization: rmax= %lg Nrand= %d\n",rmax,Nrand);
  for( i=0; i<Nrand ; i++) printf("%.15lg\n",drandom());
}
*/

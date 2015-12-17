/************************   drandom.c *****************************/
#include "include.h"

#define a 16807
#define m 2147483647
#define q 127773
#define r 2836
#define conv (1.0/(m-1))

double drandom(){
  long l;

  l=seed/q;
  seed = a*(seed-q*l) - r*l;
  if(seed < 0) seed +=m;

  return conv*(seed-1);
}

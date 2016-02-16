/************************ options.c ***********************************/
#include "include.h"
#include "fields.h"
#include "options.h"


char prog[1024];

/*Get the options function: See "man 3 getopt" for usage*/
/*Option letters are defined with this string*/
//#define OPTARGS  "hL:s:S:n:"
#define OPTARGS  "hL:m:s:S:c:n:d:"
void get_the_options(int argc,char **argv){
  int c,errflg = 0;

  if (argc==1) usage();
  
  strcpy(prog,(char *)basename(argv[0]));
  while (!errflg && (c = getopt(argc, argv, OPTARGS)) != -1){
    switch(c){
    // case 'L':
    //   L      = atoi(optarg);
    //   break;
    case 's':
      start  = atoi(optarg);
      break;
    case 'S':
      seed   = atol(optarg);
      break;
    case 'n':
      nmeasurement = atoi(optarg);
      break;
    case 'c':
      nsweep = atoi(optarg);
      break;
    case 'm':
      MU = atof(optarg);
      break;
    case 'd':
      silent = atoi(optarg);
      break;
    case 'h':
      errflg++;/*call usage*/
      break;
    default:
      errflg++;
    }/*switch*/
    if(errflg) usage();
  }/*while...*/
}/*get_the_options()*/
/* --------------------------  usage() ----------------------------- */
void usage(){
  /*Careful: New lines end with \n\ : No space after last backslacsh
    indicates line is broken....*/
  fprintf(stderr,"\
Usage: %s  [options]                                                \n\
       -m: mu (chemical potential)                                  \n\
       -s: start (0 cold, 1 hot)                                    \n\
       -S: seed  (options seed overrides the one in config)         \n\
       -c: number of sweeps per measurement of <Phi^2> and <n>      \n\
       -n: number of measurements of <Phi^2> and <n>                \n\
       -d: silent data mode (0 = normal, 1 = silent)                \n\
Monte Carlo simulation of 4d Complex Scalar Field.                  \n\
Metropolis is used by default.\nUsing the   \n\
options, the parameters of the simulations must be set for a new run\n\
(start=0,1).\n",prog);
// printed usage message "
  exit(1);
}/*usage()*/ 
/* --------------------------  locerr() ---------------------------- */
void locerr( char *errmes ){ 
  fprintf(stderr,"%s: %s Exiting....\n",prog,errmes); 
  exit(1); 
}
/* --------------------------  simmessage() ------------------------ */
/*print a message about the simulation: */

void simmessage(FILE *fp){

  // char USER[100],HOST[100],MACH[100];
  time_t t;

  time(&t);/* store time in seconds in *t. see: "man 2 time"  */
  // strcpy(USER,getenv("USER"));
  // strcpy(MACH,getenv("HOSTTYPE"));
  // strcpy(HOST,getenv("HOST"));

  fprintf(fp,"\
# ###################################################################\n\
#   4d Complex Scalar field Model for relativistic Bose gas at finite\n\
#   chemical potential with Metropolis algorithm on 4box lattice     \n\
# Run on %s#                                                         \n\
# L       = %d (Lattice linear dimension, N=L*L)                     \n\
# seed    = %ld (random number gener. seed)                          \n\
# nsweeps = %d (No. of sweeps per measurement)                       \n\
# nmeasur = %d (No. of nmeasurments)                                 \n\
# mu      = %f (Chemical Potential)                                  \n\
# start   = %d (0 cold, 1 hot)                                       \n\
# silent  = %d (0 = normal, 1 = silent)\n",
          ctime(&t),L,seed,nsweep,nmeasurement, MU,start,silent);
  fflush(fp);
}/* message()*/

/************************ options.c ************************/
#include "options.h"

char prog[1024];

/*Get the options function: See "man 3 getopt" for usage*/
/*Option letters are defined with this string*/
#define OPTARGS  "hL:M:l:m:s:S:n:d:"
options get_the_options(int argc,char **argv){
  int c,errflg = 0;

  options shelloptions;

  strcpy(prog,(char *)basename(argv[0]));
  if (argc==1) usage();

  while (!errflg && (c = getopt(argc, argv, OPTARGS)) != -1){
    switch (c) {
    case 'L':
      shelloptions.L  = atoi(optarg);
      break;
    case 'M':
      shelloptions.M  = atof(optarg);
      break;
    case 'l':
      shelloptions.LAMBDA  = atof(optarg);
      break;
    case 'S':
      shelloptions.seed   = atol(optarg);
      seed = shelloptions.seed;
      break;
    case 'n':
      shelloptions.nmeasurements = atoi(optarg);
      break;
    case 'm':
      shelloptions.MU = atof(optarg);
      break;
    case 'd':
      shelloptions.silent = atoi(optarg);
      silent = shelloptions.silent;
      break;
    case 'h':
      errflg++;/*call usage*/
      break;
    default:
      errflg++;
    }/*switch*/
    if(errflg) usage();
  }/*while...*/

  // Check to see if the shell options given are valid
  if(shelloptions.L     <  1 )
    locerr("L has not been set."   );
  if(shelloptions.seed  <  0 )
    locerr("seed has not been set.");
  if(shelloptions.MU    <  0 )
    locerr("MU has not been set.");
  if(shelloptions.nmeasurements < 0 )
    locerr("nmeasurement has not been set");

  // print out simulation message
  if (!shelloptions.silent) simmessage(stdout, shelloptions);
  return shelloptions;
}/*get_the_options()*/

/* --------------------------  usage() ------------------------ */
void usage(){
  /*Careful: New lines end with \n\ : No space after last backslacsh
    indicates line is broken....*/
  fprintf(stderr,"\
Usage: %s  [options]                                         \n\
       -L: lattice dimension size                            \n\
       -M: M (the field's mass)                              \n\
       -l: lambda (the field's coupling constant)            \n\
       -m: mu (chemical potential)                           \n\
       -S: seed  (options seed overrides the one in config)  \n\
       -n: number of measurements of <Phi^2> and <n>         \n\
       -d: silent data mode (0 = normal, 1 = silent)         \n\
Monte Carlo simulation of 4d Complex Scalar Field.           \n\
Metropolis is used by default.\n\
\n",prog);
// printed usage message "
  exit(1);
}/*usage()*/ 


/* --------------------------  locerr() ----------------------- */
void locerr( char *errmes ){ 
  fprintf(stderr,"%s: %s Exiting....\n",prog,errmes); 
  exit(1); 
}

/* ------------------------  simmessage() --------------------- */
/*print a message about the simulation: */
void simmessage(FILE *fp, options shelloptions){
  time_t t;

  time(&t);/* store time in seconds in *t. see: "man 2 time"  */

  fprintf(fp,"\
##################################################################\n\
#   Complex Scalar field Model for relativistic Bose gas at finite\n\
#   chemical potential - Metropolis algorithm on 4box lattice     \n\
# Run on %s#                                          \n\
# L       = %d (Lattice linear dimension, N=L*L*L*L)  \n\
# M       = %f (field's mass)                         \n\
# lambda  = %f (field's coupling constant)            \n\
# seed    = %ld (random number gener. seed)           \n\
# nmeasur = %d (No. of nmeasurments)                  \n\
# mu      = %f (Chemical Potential)                   \n\
# silent  = %d (0 = normal, 1 = silent)\n",
          ctime(&t), shelloptions.L, shelloptions.M, shelloptions.LAMBDA, seed, shelloptions.nmeasurements, 
          shelloptions.MU, shelloptions.silent);
  fflush(fp);
}/* message()*/

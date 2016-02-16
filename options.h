/************************** options.h ********************************/
#ifndef OPTIONS_H
#define OPTIONS_H

#include <getopt.h>
#include <string.h>
#include <libgen.h>
#include <time.h>

void usage();
void locerr( char *errmes );
void get_the_options(int argc,char **argv);
void simmessage(FILE *fp);

#endif
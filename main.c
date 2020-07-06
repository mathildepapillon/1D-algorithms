// File main.c
// This file should only contain the main function
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector_mtx.h" // vector and matrix utility functions
#include "params.h" // parameter definitions
#include "init.h" // initialization functions
#include "evolve.h" // time evolution
#include "analysis.h" // analyze the results
int main(int argc, char **argv)
{
 char *input_file; // Input file name
 double *x, *p;
 input_file = argv[1];

 ReadInParams(input_file);
 PrintParams();

 x = vector_malloc(PARAM_DATA.it_max + 1);
 p = vector_malloc(PARAM_DATA.it_max + 1);

 Initialize(x, p); //set iitial values for x and p (where iterations begin)
 Evolve(x, p); //use algorithm to obtain converging solution for x and p
 WriteResults(x, p); //store results in .dat file (analysis.c)
 return 0;
}// main
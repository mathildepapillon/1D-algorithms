// This file is init.h
#ifndef INIT_H
#define INIT_H
#include "params.h"

void ReadInParams(char *input_file); // get params from input file
void PrintParams(void); // print into terminal
void Initialize(double *x, double *p); //give initial values for parameters
#endif
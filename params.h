// header file copied form the Assignment

#ifndef PARAMS_H
#define PARAMS_H 

typedef struct params
{
 double mass; // mass
 double x_i; // initial position
 double p_i; // initial momentum
 double t_i; // initial time
 double t_f; // final time
 int it_max; // number of time intervals
 double h; // time step size
 int choice;
 int num_eq; // number of first order diff equations


  // problem specific parameters
 double k_spring; // for SHO
} Params;

Params PARAM_DATA;

//declaring functions
void ReadInParams(char *input_file);
void PrintParams(void);
#endif

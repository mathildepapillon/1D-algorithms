// This file is init.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "init.h"
#include "forces.h"
void ReadInParams(char *input)
{

 double x;
 int ix;
 FILE *input_file;
 // Order of reading-in: mass, x_i, p_i, t_i, t_f, it_max, choice, num_eq, k_spring
 input_file = fopen(input, "r");  //open file with input data

 fscanf(input_file, "%lf", &x); // mass
 PARAM_DATA.mass = x;


 fscanf(input_file, "%lf", &x); //initial position
 PARAM_DATA.x_i = x;

 fscanf(input_file, "%lf", &x); //initial momentum
 PARAM_DATA.p_i = x;

 fscanf(input_file, "%lf", &x);  // initial time
 PARAM_DATA.t_i = x;

 fscanf(input_file, "%lf", &x); //final time
 PARAM_DATA.t_f = x;

 fscanf(input_file, "%d", &ix); //number of iterations (steps)
 PARAM_DATA.it_max = ix;
 
 x = (PARAM_DATA.t_f - PARAM_DATA.t_i)/((double) PARAM_DATA.it_max); //calculate size of steps and store
 PARAM_DATA.h = x;

 fscanf(input_file, "%d", &ix); //choice of algorithm
 PARAM_DATA.choice = ix;

 fscanf(input_file, "%d", &ix);  // Number of equations -- not used here
 PARAM_DATA.num_eq = ix;

 fscanf(input_file, "%lf", &x);  //spring constant k
 PARAM_DATA.k_spring = x;

 fclose(input_file); //close file

 return;
}// ReadInParams

void PrintParams(void)
{

 double x;
 int ix;
 // Order of reading-in: mass, x_i, p_i, t_i, t_f, it_max, h, choice, num_eq, k_spring
 x = PARAM_DATA.mass;
 printf("mass = %e\n", x);
 x = PARAM_DATA.x_i;
 printf("x_i = %e\n", x);
 x = PARAM_DATA.p_i;
 printf("p_i = %e\n", x);
 x = PARAM_DATA.t_i;
 printf("t_i = %e\n", x);
 x = PARAM_DATA.t_f;
 printf("t_f = %e\n", x);
 ix = PARAM_DATA.it_max;
 printf("it_max = %d\n", ix);
 x = PARAM_DATA.h;
 printf("h = %e\n", x);
 ix = PARAM_DATA.choice;
 printf("choice = %d\n", ix);
 ix = PARAM_DATA.num_eq;
 printf("num_eq = %d\n", ix);
 x = PARAM_DATA.k_spring;
 printf("spring const k = %e\n", x);

 return;
}// PrintParams


void Initialize(double *x, double *p)
{
 double x_i, p_i, h;
 int choice;
 choice = PARAM_DATA.choice; // Get choice, h, x_i, p_i from PARAM_DATA
 h = PARAM_DATA.h;
 x_i= PARAM_DATA.x_i;
 p_i = PARAM_DATA.p_i;

 if(choice == 3) // Leapfrog 1: x[0] = x(h/2)
  {
   p[0] = p_i;
   x[0] = x_i + (h/2.0)*Velocity(p_i);
  }
 else if(choice == 4) // Leapfrog 2: p[0] = p(h/2)
  {
   x[0] = x_i;
   p[0] = p_i + (h/2.0)*Force(x_i);

} else    // For all other methods the iterations start at time 0
  {
   x[0] = x_i;
   p[0] = p_i;
}
 return;
}// Initialize

// analysis.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "analysis.h"
//implement function to write out results in txt file
void WriteResults(double *x, double *p)
{
 int it, it_max;
 FILE *output;
 double t, h, x_now, p_now;

 it_max = PARAM_DATA.it_max; // Get it_max and h from PARAM_DATA
 h = PARAM_DATA.h;

 output = fopen("Results.dat", "w");// Open the output file result.dat
 for(it=0; it<it_max; it++)
  {
   t=h*it;// Set time to t = h*it

   GetXP(x, p, &x_now, &p_now, it);
   // writes out results in the order t, position, momentum
   {
      fprintf(output, "%lf %lf %lf\n", t, x_now, p_now); //write param onto file
    }
  }// it-loop

 fclose(output); 
 
 return;
}// WriteResults



void GetXP(double *x, double *p, double *x_now, double *p_now, int it)
{
 int choice, it_max;
 double h;
 choice = PARAM_DATA.choice;
 it_max = PARAM_DATA.it_max;
 h = PARAM_DATA.h; // Get choice, it_max and h from PARAM_DATA
 if(choice == 3) // Leapfrog 1
  {

   *p_now = p[it]; //p values stya the same

   if(it == 0) // at time=0, same as others
    {
     *x_now = PARAM_DATA.x_i;
    }
   else    // at any other time, we need to go back half a step
    {
     *x_now = (x[it-1]+x[it])/2.0;
    }
  }// choice == 3

 else if(choice == 4) // leapfrog 2
  {

   *x_now = x[it]; //same as others

   if(it == 0) // at time=0, momentum same as others
    {
     *p_now = PARAM_DATA.p_i;
    }
   else  // at any other time, we need to go back half a step
    {
     *p_now = (p[it-1]+p[it])/2.0;
    }
  }// choice == 4
 else
  {
   // for other choices, just store values normally
   *x_now = x[it];
   *p_now =  p[it];
  }

 return;
}//GetXP
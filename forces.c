// This file is forces.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "forces.h"

double Velocity(double p)
{
 double v, mass;
 mass = PARAM_DATA.mass;

 v = p/mass; // calculate velocity from given momentum and mass

 return v;
}// Velocity

double Force(double x)
{
 double f, k;
// get simple harmonic oscillator force F = -k*x
 k = PARAM_DATA.k_spring; // Get k_spring from PARAM_DATA
 
 f = - k*x;
 return f;
}// Force
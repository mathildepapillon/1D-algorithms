//makes the function that will read in values for the particle's parameters. Mainly copied from Assignment 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"

void ReadInParams(char *input_file)

{
    double xr;
    int ir;
    FILE *input; // file pointer
    input = fopen(input_file, "r"); // open the file for reading

    fscanf(input, "%lf", &xr); // read from the file one number at a time
    PARAM_DATA.mass = xr; //mass

    fscanf(input, "%lf", &xr); 
    PARAM_DATA.x_i = xr; // initial position

    fscanf(input, "%lf", &xr); 
    PARAM_DATA.p_i = xr; //initial momentum

    fscanf(input, "%lf", &xr); 
    PARAM_DATA.t_i = xr; //initial time

    fscanf(input, "%lf", &xr);
    PARAM_DATA.t_f = xr; //final time

    fscanf(input, "%d", &ir); 
    PARAM_DATA.it_max = ir; // number of time intervals

    fscanf(input, "%lf", &xr); 
    PARAM_DATA.h = xr; // time step size

    fscanf(input, "%d", &ir); 
    PARAM_DATA.num_eq =ir; // number of first order diff equations

    fscanf(input, "%lf", &xr); 
    PARAM_DATA.k_spring =xr; // spring constant of SHO

    // Obtain h = (t_f - t_i)/it_max and store it
    xr = (PARAM_DATA.t_f - PARAM_DATA.t_i)/((double) PARAM_DATA.it_max);
    PARAM_DATA.h = xr;
    fclose(input); // closing file
    
    return;

}// ReadInParams


void PrintParams(void)
{
    FILE *output; //write the values read in by ReadInParams into a file
    output = fopen("InitParams.dat", "w");
    {
        fprintf(output, "Mass %lf\n", PARAM_DATA.mass); //write param onto file
        fprintf(output, "Initial position %lf\n", PARAM_DATA.x_i);
        fprintf(output, "Initial momentum %lf\n", PARAM_DATA.p_i);
        fprintf(output, "Initial time %lf\n", PARAM_DATA.t_i);
        fprintf(output, "Final time %lf\n", PARAM_DATA.t_f);
        fprintf(output, "Number of time intervals %d\n", PARAM_DATA.it_max);
        fprintf(output, "Time step size %lf\n", PARAM_DATA.h);
        fprintf(output, "Number of first order diff eq %d\n", PARAM_DATA.num_eq);
        fprintf(output, "SHO %lf\n", PARAM_DATA.k_spring);
    }
    //print out the red-in values in the Terminal
    printf("Mass = %lf \n", PARAM_DATA.mass);
    printf("Initial position = %lf \n", PARAM_DATA.x_i);
    printf("Initial momentum = %lf \n", PARAM_DATA.p_i);
    printf("Initial time = %lf \n", PARAM_DATA.t_i);
    printf("Final time = %lf \n", PARAM_DATA.t_f);
    printf("Number of time intervals = %d \n", PARAM_DATA.it_max);
    printf("Time step size = %lf \n", PARAM_DATA.h);
    printf("Number of first order diff eq = %d \n", PARAM_DATA.num_eq);
    printf("SHO = %lf \n", PARAM_DATA.k_spring);

    return;

}
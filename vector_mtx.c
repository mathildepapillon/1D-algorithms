#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector_mtx.h"

int n, m;


double *vector_malloc(int nmax) // vector memory allocation
{ 
    double *vec;
    vec = (double*) malloc(sizeof(double)*nmax);  //defining vec to be vector of size nmax
    
    //initializing
    for(n=0; n<nmax; n++)
    {   
        vec[n]=0.0;
    } //filling with zeroes
    
    return vec;
}

double **mtx_malloc(int mmax, int nmax) // matrix memory allocation
{   
    double **mtx;
    mtx = (double **) malloc(sizeof(double *)*mmax); // row indices run from 0 to mmax-1
    
    for(m=0; m<mmax; m++) // loop through the row numbers to allocate a 1D vector (column) to each row
        {mtx[m] = (double *)malloc(sizeof(double)*nmax);} //each row has nmax elements (the matrix has nmax columns)
    
    // initializing
    for(m=0; m<mmax; m++) //loops through rows
        {for(n=0; n<nmax; n++) //loops through columns
            {mtx[m][n]=0.0;}} //fills with zeroes (initializing)                                    
    
    return mtx;
}
void mtx_free(double **mtx, int mmax)
{ // matrix memory de-allocation
    for(m=0; m<=mmax; m++)
        {free(mtx[m]);} //free rows
    free (mtx); //free pointers to rows
}


void CopyVector(double *a, double *b, int nmax)
{
    for(n=0; n<nmax; n++)
    {
        b[n]=a[n];
    } // copy a to b. the index runs from 0 to nmax-1
}   

int *int_vector_malloc(int nmax) // integer vector allocation
{
    int *ivar;
    ivar = (int*) malloc(sizeof(int)*nmax);

    return ivar;
}
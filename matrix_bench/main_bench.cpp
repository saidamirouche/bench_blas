#include <iostream>
#include "matrix.h"
#include <random>
#include "cblas.h"
#include "bench_func.h"

int main(int argc, char* argv[])
{
   int type , mrows, mcols,mat_type;
   float p1,temps;
   clock_t t1, t2;

   double * res_mat;


  // Getting arguments to work with : Type of matrix (Sparse or full), Rate of Sparse in matrix (%), Dimensions of the matrix, the type of multiplication to use (0 - Naive methode, 1 - Using BLAS)

   srand(time(NULL));
   type =atoi(argv[1]);
   p1 = atoi(argv[2]);
   p1 = p1/100;
   mrows = atoi(argv[4]);
   mcols = atoi(argv[3]);
   mat_type = atoi(argv[5]);


   res_mat = (double *) malloc( mrows * mcols * sizeof(double) );

   Matrix m1(mrows,mcols);
   Matrix m2(mrows,mcols);
   Matrix res(mrows,mcols);
   m1.mat_insert(mat_type,p1);
   m2.mat_insert(mat_type,p1);

   if (type==0)
   res = m1*m2;
   else
   res_mat = m1.blas_mul(m2);





}

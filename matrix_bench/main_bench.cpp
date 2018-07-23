#include <iostream>
#include "matrix.h"
#include <random>
#include "cblas.h"

Matrix insert(Matrix mat, int t, int rows,int cols, float pl){
   int p,i,j,count=0;
  if (t==1){
    for (i = 0; i <rows; ++i) {
        for (j = 0; j <cols; ++j) {
             mat(i,j) = rand()%((rows*cols)+1);
           }
         }

  }   else {
     p = (rows*cols) * pl;
       for (int i = 0; i <rows; ++i) {
        for (int j = 0; j <cols; ++j) {
             mat(i,j) = 0;
           }
         }
    while (count<p) {
      i = rand()%rows;
      j = rand()%cols;
      mat(i,j) = rand()%((rows*cols)+1);
      count = count+1;
    }
  }
  return mat;
}

void display(Matrix mat, int rows, int cols) {
int i, j ;
       for ( i = 0; i < rows;++i) {
          for (j = 0; j < cols; ++j) {
            std::cout << mat(i,j) << " ";
  }
  std::cout  << '\n';
  }
}


int main()
{
   int N,type;
   N = 15;
   type =2;
   float p1=0.1;
   srand(time(NULL));
   int mrows, mcols;
   mrows = N;
   mcols = N;
   Matrix m1(mrows,mcols);
   Matrix m2(mrows,mcols);
   Matrix res(mrows,mcols);

   m1 = insert(m1,type,mrows,mcols,p1);
   m2 = insert(m2,type,mrows,mcols,p1);

  // cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,mrows,mrows,mrows,1,m1,mrows,m2 ,mrows,0,res,mrows);


   display(m1,mrows,mcols);
}

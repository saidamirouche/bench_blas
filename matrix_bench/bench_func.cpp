#include <iostream>
#include "matrix.h"
#include <random>
#include "cblas.h"
#include "bench_func.h"


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

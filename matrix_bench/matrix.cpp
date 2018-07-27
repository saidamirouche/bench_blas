
#include <stdexcept>
#include "matrix.h"
#include "cblas.h"



Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
    allocSpace();
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            p[i][j] = 0;
        }
    }
}

Matrix::Matrix() : rows_(1), cols_(1)
{
    allocSpace();
    p[0][0] = 0;
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows_; ++i) {
        delete[] p[i];
    }
    delete[] p;
}

Matrix::Matrix(const Matrix& m) : rows_(m.rows_), cols_(m.cols_)
{
    allocSpace();
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            p[i][j] = m.p[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{
    if (this == &m) {
        return *this;
    }

    if (rows_ != m.rows_ || cols_ != m.cols_) {
        for (int i = 0; i < rows_; ++i) {
            delete[] p[i];
        }
        delete[] p;

        rows_ = m.rows_;
        cols_ = m.cols_;
        allocSpace();
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            p[i][j] = m.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            p[i][j] += m.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& m)
{
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            p[i][j] -= m.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::mat_insert(int t, float pl){
   int p10,i,j,count=0;
   Matrix temp(rows_, cols_);

  if (t==1){
    for (i = 0; i <rows_; ++i) {
        for (j = 0; j <cols_; ++j) {
             temp.p[i][j] = rand()%((rows_*cols_)+1);
           }
         }

  }   else {
     p10 = (rows_*cols_) * pl;
       for (int i = 0; i <rows_; ++i) {
        for (int j = 0; j <cols_; ++j) {
             temp.p[i][j] = 0;
           }
         }
    while (count<p10) {
      i = rand()%rows_;
      j = rand()%cols_;
      temp.p[i][j] = rand()%((rows_*cols_)+1);
      count = count+1;
    }
  }
  return (*this=temp);
}
double* Matrix::blas_mul( Matrix& m) {
   clock_t t1, t2;
    float temps;
   double * mat1;
   double * mat2;
   double * res_mat;
   res_mat = (double *) malloc(rows_ *cols_ * sizeof(double) );
   mat1=  convertir();
   mat2=  m.convertir();
   t1 = clock();

  cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,rows_,rows_,rows_,1, mat1,rows_,mat2 ,rows_,0,res_mat,rows_);
  t2 = clock();
  temps = (float)(t2-t1)/CLOCKS_PER_SEC;
  std::cout << "temps d'execution avec BLAS :  " << temps << '\n';
return res_mat;

}

void Matrix::display() {
int i, j ;
       for ( i = 0; i < rows_;++i) {
          for (j = 0; j < cols_; ++j) {
            std::cout << p[i][j] << " ";
  }
  std::cout  << '\n';
  }
}

Matrix& Matrix::operator*=(const Matrix& m)
{
  float temps;
  clock_t t1, t2;
    Matrix temp(rows_, m.cols_);
    t1 = clock();

    for (int i = 0; i < temp.rows_; ++i) {
        for (int j = 0; j < temp.cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                temp.p[i][j] += (p[i][k] * m.p[k][j]);
            }
        }
    }
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    std::cout << "temps d'execution en multiplication naif : " << temps << '\n';

    return (*this = temp);
}

Matrix& Matrix::operator*=(double num)
{
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            p[i][j] *= num;
        }
    }
    return *this;
}

double* Matrix::convertir() {
  int i, j,k;
  double *arr;
  k=0;
  arr = (double *) malloc(rows_* cols_ * sizeof(double) );

  for ( i = 0; i < rows_;i++) {
            for (j = 0; j < cols_; j++) {
              arr[k] = p[i][j];
              k++;
            }
  }
  return arr;
}

void Matrix::allocSpace()
{
    p = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
        p[i] = new double[cols_];
    }
}


Matrix operator+(const Matrix& m1, const Matrix& m2)
{
    Matrix temp(m1);
    return (temp += m2);
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
    Matrix temp(m1);
    return (temp -= m2);
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
    Matrix temp(m1);
    return (temp *= m2);
}

Matrix operator*(const Matrix& m, double num)
{
    Matrix temp(m);
    return (temp *= num);
}

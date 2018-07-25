
#include <stdexcept>
#include "matrix.h"
#include "cblas.h"



Matrix::Matrix(int rows, int cols, int type) : rows_(rows), cols_(cols), mul_type(type)
{
    allocSpace();
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            p[i][j] = 0;
        }
    }
}

Matrix::Matrix() : rows_(1), cols_(1), mul_type(1)
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

Matrix::Matrix(const Matrix& m) : rows_(m.rows_), cols_(m.cols_), mul_type(m.mul_type)
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


double* Matrix::set_mul(const Matrix& m) {
   clock_t t1, t2;
    float temps;
  Matrix temp(m.rows_, m.cols_,m.mul_type);

if (mul_type==0) {
for (int i = 0; i < temp.rows_; ++i) {
        for (int j = 0; j < temp.cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                temp.p[i][j] += (p[i][k] * m.p[k][j]);
            }
        }
    }
    return temp.convertir();

} else {

   double * mat1;
   double * mat2;
   double * res_mat;
   res_mat = (double *) malloc(rows_ *cols_ * sizeof(double) );
   mat1=  convertir();
   mat2=  temp.convertir();
   t1 = clock();

  cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,rows_,rows_,rows_,1, mat1,rows_,mat2 ,rows_,0,res_mat,rows_);
  t2 = clock();
  temps = (float)(t2-t1)/CLOCKS_PER_SEC;
  std::cout << "temps d'execution avec BLAS :  " << temps << '\n';
return res_mat;
}
}



Matrix& Matrix::operator*=(const Matrix& m)
{

    Matrix temp(rows_, m.cols_,m.mul_type);
    for (int i = 0; i < temp.rows_; ++i) {
        for (int j = 0; j < temp.cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                temp.p[i][j] += (p[i][k] * m.p[k][j]);
            }
        }
    }
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

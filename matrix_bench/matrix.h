
#ifndef MATRIX_H1
#define MATRIX_H1

#include <iostream>

class Matrix {
    public:
        Matrix(int, int);
        Matrix();
        ~Matrix();
        Matrix(const Matrix&);
        Matrix& operator=(const Matrix&);

        inline double& operator()(int x, int y) { return p[x][y]; }
        double* convertir();
        Matrix& operator+=(const Matrix&);
        Matrix& operator-=(const Matrix&);
        Matrix& operator*=(const Matrix&);
        Matrix& operator*=(double);
        Matrix& mat_insert(int t, float pl);
         void  display();
        double *blas_mul( Matrix&);
    private:
        int rows_, cols_;
        double **p;

        void allocSpace();
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
#endif

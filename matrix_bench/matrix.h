
#ifndef MATRIX_H1
#define MATRIX_H1

#include <iostream>

class Matrix {
    public:
        Matrix(int, int,int);
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
        double *set_mul(const Matrix&);
    private:
        int rows_, cols_, mul_type;
        double **p;

        void allocSpace();
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
#endif

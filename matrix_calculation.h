#ifndef MATRIX_CALCULATION_H
#define MATRIX_CALCULATION_H

#include "basic_matrix_operator.h"

/* X = A + B */
int matrixSum(Matrix* X, Matrix* A, Matrix* B);

/* X = A - B */
int matrixSubstract(Matrix* X, Matrix* A, Matrix*B);

/* X = A.*B */
int matrixScalarMultiply(Matrix *X, Matrix* A, Matrix* B);

/* X = A * B */
int matrixMultiply(Matrix* X, Matrix* A, Matrix* B);

/* X = transpose(A) */
int transpose(Matrix* X, Matrix *A);

#endif
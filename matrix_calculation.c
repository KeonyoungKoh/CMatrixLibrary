#include <stdio.h>
#include <stdlib.h>
#include "basic_matrix_operator.h"
#include "matrix_calculation.h"

int matrixSum(Matrix* X, Matrix* A, Matrix* B){
    if((A->rows != B->rows) || (A->cols != B->cols)) return 0;
    if((X->rows != A->rows) || (X->cols != B->cols)) return 0;
    if((X->rows != B->rows) || (X->cols != B->cols)) return 0;

    for(int i=1; i<=X->rows; i++){
        for(int j=1; j<=X->cols; j++){
            setElement(X, i, j, getElement(A, i, j) + getElement(B,i, j));
        }
    }
    return 1;
}

int matrixSubstract(Matrix* X, Matrix* A, Matrix*B){
    if((A->rows != B->rows) || (A->cols != B->cols)) return 0;
    if((X->rows != A->rows) || (X->cols != B->cols)) return 0;
    if((X->rows != B->rows) || (X->cols != B->cols)) return 0;

    for(int i=1; i<=X->rows; i++){
        for(int j=1; j<=X->cols; j++){
            setElement(X, i, j, getElement(A, i, j) - getElement(B,i, j));
        }
    }
    return 1;
}

int matrixScalarMultiply(Matrix *X, Matrix* A, Matrix* B){
    if((A->rows != B->rows) || (A->cols != B->cols)) return 0;
    if((X->rows != A->rows) || (X->cols != B->cols)) return 0;
    if((X->rows != B->rows) || (X->cols != B->cols)) return 0;

    for(int i=1; i<=X->rows; i++){
        for(int j=1; j<=X->cols; j++){
            setElement(X, i, j, getElement(A, i, j) * getElement(B,i, j));
        }
    }
    return 1;
}

int matrixMultiply(Matrix* X, Matrix* A, Matrix* B){
    if((A->cols != B->rows) || (X->rows != A->rows) || (X->cols != B->cols)) return 0;

    float saveElem;
    for(int i=1; i<=X->rows; i++){
        for(int j=1; j<=X->cols; j++){
         saveElem = 0;
            for(int k=1; k<=A->cols; k++){
             saveElem += getElement(A, i, k) * getElement(B, k, j);
            }
            setElement(X, i, j, saveElem);
        }
    }
    return 1;
}

int transpose(Matrix* X, Matrix *A){
    if((X->rows != A->cols) || (X->cols != A->rows)) return 0;

    for(int i=1; i<=X->rows; i++){
        for(int j=1; j<=X->cols; j++){
            setElement(X, i, j, getElement(A, j, i));
        }
    }
    return 1;
}

int matrixTransposeMultiply(Matrix *X, Matrix *A){
    if((X->rows != A->cols) || (X->cols != A->cols)) return 0;

    float saveElem;
    for(int i=1; i<=X->rows; i++){
        for(int j=1; j<=X->cols; j++){
            saveElem = 0;
            for(int k=1; k<=A->rows; k++){
                saveElem += getElement(A, k, i) * getElement(A, k, j);
            }
            setElement(X, i, j, saveElem);            
        }
    }
    return 1;
}

void test1(){
    struct Matrix* X = matrixConstructor(3, 3);
    float datalist1[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    matrixInitializer(X, datalist1, 3, 3);

    struct Matrix* A = matrixConstructor(3, 3);
    float datalist2[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    matrixInitializer(A, datalist2, 3, 3);

    struct Matrix* B = matrixConstructor(3, 3);
    float datalist3[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    matrixInitializer(B, datalist3, 3, 3);

    printf("X =");
    matrixPrint(X);
    printf("A =");
    matrixPrint(A);
    printf("B =");
    matrixPrint(B);

    /* sum check */
    printf("A + B =");
    matrixSum(X, A, B);
    matrixPrint(X);

    /* substraction check */
    printf("A - B =");
    matrixSubstract(X, A, B);
    matrixPrint(X);

    /* scalar mult. check*/
    printf("A .* B =");
    matrixScalarMultiply(X, A, B);
    matrixPrint(X);

    /* mult. check */
    printf("A * B =");
    matrixMultiply(X, A, B);
    matrixPrint(X);

    /* transpose check */
    printf("transpose(B) =");
    transpose(X, B);
    matrixPrint(X);

    /* transpose and multiply check */
    printf("BTB =");
    matrixTransposeMultiply(X, B);
    matrixPrint(X);
    
    matrixDestructor(X);
    matrixDestructor(A);
    matrixDestructor(B);
}

int main(){
    test1();
}
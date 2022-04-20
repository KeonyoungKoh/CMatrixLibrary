#ifndef BASIC_MATRIX_OPERATOR_H
#define BASIC_MATRIX_OPERATOR_H

typedef struct Matrix {
    int rows;
    int cols;
    float *data;
}Matrix;

/* returns whether or not matrix indexing is valid. 1 if valid, 0 if invalid*/
int isValidRange(Matrix* mat, int row, int col);

/* returns matrix element at certain index */
float *elem(Matrix* mat, int row, int col);

/* getter and setter */
float getElement(Matrix *mat, int row, int col);
int setElement(Matrix *mat, int row, int col, float val);

/* construct a matrix and returns its pointer*/
struct Matrix* matrixConstructor(int row, int col);

/* 
 * initialize a constructed matrix and returns success/failure 
 * dataList : 2 dimensional array of floats used to initialize matrix
 * listRows : # of rows of dataList
 * listCols : # of cols of dataList
 */
int matrixInitializer(Matrix* mat, float* dataList, int listRows, int listCols);

/* destruct a matrix */
void matrixDestructor(Matrix* mat);

void matrixPrint(Matrix* mat);

#endif
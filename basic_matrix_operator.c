#include <stdio.h>
#include <stdlib.h>
#include "basic_matrix_operator.h"

int isValidRange(Matrix* mat, int row, int col){
    return (row > 0) && (row <= mat->rows) && (col > 0) && (col <= mat->cols);
}

float *elem(Matrix* mat, int row, int col){
    if(!isValidRange(mat, row, col)) return NULL;
    else return &(mat->data)[mat->cols*(row-1) + col];
}

float getElement(Matrix *mat, int row, int col){
    return *elem(mat, row, col);
}

int setElement(Matrix *mat, int row, int col, float val){
    if(!isValidRange(mat, row, col)) return 0;
    else{
        // (mat->data)[mat->cols*(row-1) + col] = val;
        *elem(mat, row, col) = val;
        return 1;
    }
}

struct Matrix* matrixConstructor(int row, int col){
    struct Matrix* mat = (struct Matrix *)malloc(sizeof(struct Matrix));

    mat->rows = row;
    mat->cols = col;
    mat->data = (float *)malloc(sizeof(float)*row*col);

    return mat;
}

int matrixInitializer(Matrix* mat, float* dataList, int listRows, int listCols){
    if((listRows != mat->rows) || (listCols != mat->cols)) return 0;
    else{
        for(int i = 1; i <= mat->rows; i++){
            for(int j = 1; j <= mat->cols; j++){
                if(!setElement(mat, i, j, dataList[listCols*(i-1)+j-1])) return 0;
            }
        }
    }
    return 1;
}

void matrixDestructor(Matrix* mat){
    free(mat->data);
    free(mat);
}

void matrixPrint(Matrix* mat){
    printf("\n");
    for(int i=1; i<=mat->rows; i++){
        for(int j=1; j<=mat->cols; j++){
            printf("%f ", getElement(mat, i,j));
        }
        printf("\n");
    }

}

int main(){
    /* matrix construction, initialization check */
    struct Matrix* newMat = matrixConstructor(3, 3);
    float datalist[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    matrixInitializer(newMat, datalist, 3, 3);

    /* isValidRange check */
    printf("validity check, accessing valid index : %d\n", isValidRange(newMat, 3, 3));
    printf("validity check, accessing invalid index : %d\n", isValidRange(newMat, 4, 1));

    /* elem, getElement check */
    printf("\nindexing check:\n");
    matrixPrint(newMat);

    /* setElement check */
    printf("\nsetelement check:\n");
    for(int i=1; i<=newMat->rows; i++){
        for(int j=1; j<=newMat->cols; j++){
            setElement(newMat, i, j, 0);
        }
    }
    matrixPrint(newMat);

    /* deconstruct check */
    printf("\ninitial address : %x %x\n", newMat, newMat->data);
    matrixDestructor(newMat);
    printf("deallocated? : %x %x\n", newMat, newMat->data);
    

}
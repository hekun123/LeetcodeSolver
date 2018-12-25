#include <stdio.h>

void rotate(int matrix[][10], int matrixRowSize, int *matrixColSizes) {
    int i, j;
    int rowSize = matrixRowSize;
    for(i = 0 ; i < matrixRowSize/2; i ++) {
        for(j = 0 ; j < rowSize-1; j ++) {
            int aa = matrix[i][i+j];
            int bb = matrix[i+j][matrixRowSize-i-1];
            int cc = matrix[matrixRowSize-i-1][matrixRowSize-i-j-1];
            int dd = matrix[matrixRowSize-i-j-1][i];

            matrix[i+j][matrixRowSize-i-1] = aa;
            matrix[matrixRowSize-i-1][matrixRowSize-i-j-1] = bb;
            matrix[matrixRowSize-i-j-1][i] = cc;
            matrix[i][i+j] = dd;
        }
        rowSize -= 2;
    }
    *matrixColSizes = matrixRowSize;
}

int main() {
    int a[][10]={
    {1,2,3},
  {4,5,6},
  {7,8,9}
    };
    int n;
    rotate(a, 3, &n);
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

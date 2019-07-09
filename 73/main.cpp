#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    if(matrixRowSize <= 0 || matrixColSize <= 0){
        return ;
    }
    bool row_visit[matrixRowSize];
    bool col_visit[matrixColSize];
    memset(row_visit, false, sizeof(row_visit));
    memset(col_visit, false, sizeof(col_visit));

    for(int i = 0 ; i < matrixRowSize ; i ++){
        for(int j =  0 ; j < matrixColSize ; j ++){
            if(matrix[i][j] == 0){
                row_visit[i] = true;
                col_visit[j] = true;
            }
        }
    }
    for(int i = 0 ; i < matrixRowSize ; i ++){
        if(row_visit[i]){
            for(int j = 0 ; j < matrixColSize ; j ++){
                matrix[i][j] = 0;
            }
        }
    }
    for(int i = 0 ; i < matrixColSize ; i ++){
        if(col_visit[i]){
            int col = i;
            for(int j = 0 ; j < matrixRowSize; j ++){
                matrix[j][i] = 0;
            }
        }
    }
}

int main(){

    int matrix[][100] = {
        {0,1,2,0},
        {3,0,0,2},
        {1,3,1,5}
    };
    int n = 3;
    int m = 4;
    int *p[n];
    for(int i = 0 ; i < n ; i ++){
        p[i] = matrix[i];
    }
    setZeroes(p, n, m);
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}

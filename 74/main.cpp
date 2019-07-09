#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if(matrixRowSize <= 0 || matrixColSize <= 0){
        return false;
    }
    if(target < matrix[0][0]){
        return false;
    }
    int left = 0;
    int right = matrixRowSize-1;
    int mid;
    while(left <= right){
        mid = (left+right)/2;

        if(matrix[mid][0] > target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    int row = right;
    left = 0;
    right = matrixColSize - 1;
    while(left <= right){
        mid = (left+right)/2;

        if(matrix[row][mid] == target){
            break;
        }else if(matrix[row][mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    if(matrix[row][mid] == target){
        return true;
    }else{
        return false;
    }
}

int main(){
    int matrix[][100] = {
        {2,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
        {52, 55, 58, 60}
    };
    int n = 4;
    int m = 4;
    int *p[n];
    for(int i = 0 ; i < n ; i ++){
        p[i] = matrix[i];
    }
    printf("%s\n", searchMatrix(p, n, m, 58)?"YES":"NO");
    return 0;
}

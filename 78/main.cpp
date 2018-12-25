#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **returnAns;
int *returnColSize;
int cnt;

void dfs(int *nums, int numsSize, int *temp, int length, int step, int i){
    if(step == length){
        cnt ++;
        returnAns = (int **)realloc(returnAns, sizeof(int*)*cnt);
        returnAns[cnt-1] = (int *)malloc(sizeof(int)*length);
        for(int j = 0 ; j < length ; j ++){
            returnAns[cnt-1][j] = temp[j];
        }
        returnColSize = (int *)realloc(returnColSize, sizeof(int)*cnt);
        returnColSize[cnt-1] = length;
    }else{
        for( ; i  < numsSize-length+step+1 ; i ++){
            temp[step] = nums[i];
            dfs(nums, numsSize, temp, length, step+1, i+1);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    returnAns = NULL;
    returnColSize = NULL;
    cnt = 0;
    for(int i = 0 ; i <= numsSize; i ++ ){
        int *temp = (int *)malloc(sizeof(int )*i);
        dfs(nums, numsSize, temp, i, 0, 0);
    }
    (*columnSizes) = returnColSize;
    (*returnSize) = cnt;
    return returnAns;
}

int main(){
    int num[] = {1,2,3,4};
    int *col;
    int ansCnt;
    int **ans = subsets(num, 4, &col, &ansCnt);
    for(int i = 0 ; i < ansCnt ; i ++){
        for(int j = 0 ; j < col[i] ; j ++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

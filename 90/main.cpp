#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **returnVector;
int *returnVectCol;
int cnt;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}


void dfs(int *pstNums, int iNumsSize, int i, int *pstTmpVect, int iTmpVectLen, int iLen){

    if(iTmpVectLen >= iLen){
        cnt ++;
        returnVector = (int **) realloc(returnVector, sizeof(int *)*cnt);
        if(iLen == 0){
            returnVector[cnt-1] = NULL;
        }else{
            returnVector[cnt-1] = (int *) malloc(sizeof(int)*iLen);
        }

        returnVectCol = (int *) realloc(returnVectCol, sizeof(int)*cnt);
        returnVectCol[cnt-1] = iLen;
        for(int j = 0 ; j < iLen ; j ++){
            returnVector[cnt-1][j] = pstTmpVect[j];
        }
        return;
    }
    if(i >= iNumsSize){
        return;
    }

    int iSameLen = 1, k = 1;
    while(i+k < iNumsSize && pstNums[i] == pstNums[i+k]){
        iSameLen ++;
        k ++;
    }
    for(int j = 0 ; j <= iSameLen && iTmpVectLen<=iLen; j ++){
        dfs(pstNums, iNumsSize, i+iSameLen, pstTmpVect, iTmpVectLen, iLen);
        pstTmpVect[iTmpVectLen++] = pstNums[i];
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    returnVector = NULL;
    returnVectCol = NULL;
    cnt = 0;
    int *aTmpVect = (int *) malloc(sizeof(int )*(numsSize+3));
    for(int i = 0 ; i <= numsSize; i ++){
        dfs(nums, numsSize, 0, aTmpVect, 0, i);
    }
    (*columnSizes) = returnVectCol;
    (*returnSize) = cnt;
    return returnVector;
}

int main(){
    int vNums[] = {4,4,4,1,4};
    int **ans;
    int *col;
    int num;
    ans = subsetsWithDup((int *)&vNums, sizeof(vNums)/sizeof(vNums[0]), &col, &num);
    for(int i = 0 ; i < num ; i ++){
        for(int j = 0 ; j < col[i] ; j ++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

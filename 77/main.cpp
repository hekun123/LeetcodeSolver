#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **returnAns;
int *returnColSize;
int cnt;

struct node{
    int **V;
    int *V_vsize;
    int V_num;
};

void test(){

    int V_num = VecotrNum;  //记录V中总共有多少个向量
    int **V = (int **)malloc(sizeof(int *)*VectorNum);  //二维向量
    int *V_vsize = (int *)malloc(sizeof(int)*VectorNum);    //记录每一个向量的长度

    for(int i = 0 ; i < VectorNum; i ++){
        V[i] = (int *)malloc(sizeof(int)*Vector_i_Size);
        memcpy(V[i], v_i, v_i_size);
    }
}

void dfs(int *num, int i, int n, int k, int step){
    if(step == k){
        cnt ++;
        returnAns = (int **)realloc(returnAns, sizeof(int*)*cnt);
        returnAns[cnt-1] = (int *)malloc(sizeof(int)*k);
        for(int j = 0 ; j < k ; j ++){
            returnAns[cnt-1][j] = num[j];
        }
        returnColSize = (int *)realloc(returnColSize, sizeof(int)*cnt);
        returnColSize[cnt-1] = k;
        return ;
    }else{

        for(; i < n-k+step+1; i ++){
            num[step] = i+1;
            dfs(num, i+1, n, k, step+1);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int** columnSizes, int* returnSize) {
    returnAns = NULL;
    returnColSize = NULL;
    cnt = 0;
    int *num = (int *)malloc(sizeof(int)*k);
    dfs(num, 0, n, k, 0);
    (*columnSizes) = returnColSize;
    (*returnSize) = cnt;
    return returnAns;
}

int main(){
    int *col = NULL;
    int cnt = 0;
    int n = 5;
    int k = 3;
    int **ans = combine(n, k, &col, &cnt);
    for(int i = 0 ; i < cnt ; i ++){
        for(int j = 0 ; j < col[i]; j ++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

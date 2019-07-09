#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int **matrix, int matrixRowSize, int matrixColSize) {
    if(matrixRowSize == 0 || matrixColSize == 0)return NULL;
    int *ans = (int *)malloc(sizeof(int)*(matrixRowSize*matrixColSize));
    bool visit[matrixRowSize][matrixColSize];
    memset(visit, 0, sizeof(visit));
    int flag = 1, cnt = 0;
    int x = 0, y = 0;
    while(flag){
        //向右
        while(true){
            if(y+1 >= matrixColSize || visit[x][y+1] == 1)break;
            flag = 0;
            ans[cnt ++] = matrix[x][y];
            visit[x][y] = 1;
            y ++;
        }
        //向下
        while(true){
            if(x+1 >= matrixRowSize || visit[x+1][y] == 1)break;
            flag = 0;
            ans[cnt ++] = matrix[x][y];
            visit[x][y] = 1;
            x ++;
        }
        //向左
        while(true){
            if(y <= 0 || visit[x][y-1] == 1)break;
            flag = 0;
            ans[cnt ++] = matrix[x][y];
            visit[x][y] = 1;
            y --;
        }
        //向上
        while(true){
            if(x <= 0 || visit[x-1][y] == 1)break;
            flag = 0;
            ans[cnt ++] = matrix[x][y];
            visit[x][y] = 1;
            x--;
        }
        if(flag)break;
        else flag = 1;
    }
    ans[cnt ++] = matrix[x][y];
    return ans;
}

int main(){
    int n = 3;
    int m = 3;
    int matrix[][5] = {
        {1, 2, 3},{4, 5, 6},{7, 8, 9}
    };
    int *q[5];
    for(int i = 0 ; i < n ; i ++){
        q[i] = matrix[i];
    }

    int *ans = spiralOrder(q, n, m);
    for(int i = 0 ; i < n*m; i ++ ){
        printf("%d\t", ans[i]);
    }
    printf("\n");
    return 0;
}

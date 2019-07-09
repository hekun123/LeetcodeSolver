#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt;

void getGradient(int x, int y, int n, int *gradientLeft, int *gradientRight){
    int num = 0;
    if(x > y){
        num = x - y;
        (*gradientRight) = n - num - 1;
    }else if(x < y){
        num = y - x;
        (*gradientRight) = n + num - 1;
    }else{
        (*gradientRight) = n - 1;
    }
    (*gradientLeft) = x + y;
}

void dfs(char **tempMap, int *visit_x, int *visit_left, int *visit_right, int step, int n){
    if(step == n){
        cnt ++;
        return ;
    }
    int left = 0, right = 0;
    for(int j = 0 ; j < n; j ++){
        getGradient(j, step, n, &left, &right);
        if(visit_x[j] == 0 && visit_left[left] == 0 && visit_right[right] == 0){
            tempMap[j][step] = 'Q';
            visit_x[j] = 1;
            visit_left[left] = 1;
            visit_right[right] = 1;
            dfs(tempMap, visit_x, visit_left, visit_right, step+1, n);
            visit_x[j] = 0;
            visit_left[left] = 0;
            visit_right[right] = 0;
            tempMap[j][step] = '.';
        }
    }
}

int totalNQueens(int n) {
    int *visit_x = (int *)malloc(sizeof(int)*n);
    int *visit_left = (int *)malloc(sizeof(int)*(2*(n-1)+1));
    int *visit_right = (int *)malloc(sizeof(int)*(2*(n-1)+1));
    char **tempMap = (char **)malloc(sizeof(char*)*n);
    int i, j;

    memset(visit_x, 0, sizeof(int)*n);
    memset(visit_left, 0, sizeof(int)*(2*(n-1)+1));
    memset(visit_right, 0, sizeof(int)*(2*(n-1)+1));
    cnt = 0;

    for(i = 0 ; i < n ; i ++){
        tempMap[i] = (char *)malloc(sizeof(char)*n);
        for(j = 0 ; j < n ; j ++){
            tempMap[i][j] = '.';
        }
    }
    dfs(tempMap, visit_x, visit_left, visit_right, 0, n);
    return cnt;
}

int main()
{
    int n = 8;
    printf("%d\n", totalNQueens(n));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int i, j;
    int **returnAns = NULL;
    returnAns = (int **)malloc(sizeof(int *)*n);
    for(i = 0 ; i < n; i ++){
        returnAns[i] = (int *)malloc(sizeof(int)*n);
    }

    int dirt[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    bool visit[n][n];
    memset(visit, false, sizeof(visit));
    int x = 0, y = 0;
    int cnt = 0;
    for(i = 0 ; i < n/2; i ++){
        j = 0;
        x = i;
        y = i;
        while(true){
            returnAns[x][y] = cnt++;
            visit[x][y] = true;
            while(x+dirt[j][0] >= n || y+dirt[j][1] >= n
               || x+dirt[j][0] < 0 || y+dirt[j][1] < 0
               || visit[x+dirt[j][0]][y+dirt[j][1]] == true){

                j ++;
                if(j >= 4)break;
           }
           if(j >= 4)break;
            x += dirt[j][0];
            y += dirt[j][1];
        }
    }
    if(n%2){
        returnAns[n/2][n/2] = cnt++;
    }
    return returnAns;
}

int main()
{
    int n = 3;
    int **ans = generateMatrix(n);
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ;  j < n ; j ++){
            printf("%d\t", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int map[obstacleGridRowSize][obstacleGridColSize];
    int flag = 0;
    if(obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1] == 1){
        return 0;
    }
    for(int i = obstacleGridRowSize-1; i >=0 ; i --){
        if(obstacleGrid[i][obstacleGridColSize-1] == 1){
            flag = 1;
        }
        if(flag){
            map[i][obstacleGridColSize-1] = 0;
        }else{
            map[i][obstacleGridColSize-1] = 1;
        }
    }
    flag = 0;
    for(int i = obstacleGridColSize-1 ; i >= 0; i -- ){
        if(obstacleGrid[obstacleGridRowSize-1][i] == 1){
            flag = 1;
        }
        if(flag){
            map[obstacleGridRowSize-1][i] = 0;
        }else{
            map[obstacleGridRowSize-1][i] = 1;
        }
    }
    for(int i = obstacleGridRowSize-2 ; i >= 0; i --){
        for(int j = obstacleGridColSize-2; j >= 0 ; j --){
            if(obstacleGrid[i][j] == 1){
                map[i][j] = 0;
            }else{
                map[i][j] = map[i+1][j] + map[i][j+1];
            }
        }
    }
    return map[0][0];
}

int main()
{
    int n = 3;
    int map[][100]{
        {1,0,0},
        {0,0,0},
        {0,0,0}
    };
    int *mapPtr[n];
    for(int i = 0 ; i < n ; i ++){
        mapPtr[i] = map[i];
    }
    printf("%d\n", uniquePathsWithObstacles(mapPtr, 3, 3));
    return 0;
}

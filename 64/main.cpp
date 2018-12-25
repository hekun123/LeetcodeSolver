#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b){
    return a<b?a:b;
}
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int map[gridRowSize][gridColSize];

    for(int i = gridRowSize-1; i >= 0; i --){
        for(int j = gridColSize-1 ;j >= 0 ; j --){
            if(i == gridRowSize-1 && j == gridColSize-1){
                map[i][j] = grid[i][j];
            }else if(i == gridRowSize-1){
                map[i][j] = grid[i][j] + map[i][j+1];
            }else if(j == gridColSize-1){
                map[i][j] = grid[i][j] + map[i+1][j];
            }else{
                map[i][j] = min(grid[i][j] + map[i][j+1], grid[i][j] + map[i+1][j]);
            }
        }
    }
    return map[0][0];
}

int main()
{
    int n = 3;
    int map[][100]{
        {1,8,1},
        {1,5,1},
        {4,2,1}
    };
    int *mapPtr[n];
    for(int i = 0 ; i < n ; i ++){
        mapPtr[i] = map[i];
    }
    printf("%d\n", minPathSum(mapPtr, 3, 3));
    return 0;
}

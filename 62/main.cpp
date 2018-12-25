#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int uniquePaths(int m, int n) {
    int map[m][n];
    for(int i = m-1 ; i >= 0; i --){
        for(int j = n-1; j >= 0 ; j --){
            if(i == m-1 || j == n-1){
                map[i][j] = 1;
            }else{
                map[i][j] = map[i+1][j] + map[i][j+1];
            }
        }
    }
    return map[0][0];
}

int main(){
    printf("%d\n", uniquePaths(7, 3));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial[] = {
1,1,2,6,24,120,
720,5040,40320,362880,3628800,
39916800,479001600,6227020800,6227020800,1307674368000
};

char *indexToString(int *indexArray, int n){
    char *returnAns = (char *)malloc(sizeof(char)*(n+1));
    int visit[n];
    memset(visit, 0, sizeof(visit));
    for(int i = 0 ; i < n ; i ++){
        int cnt = 0;
        for(int j = 0 ; j < n ; j ++){
            if(!visit[j]){
                cnt ++;
            }
            if(cnt == indexArray[i]){
                visit[j] = 1;
                returnAns[i] = j+1+'0';
                break;
            }
        }
    }
    returnAns[n] = '\0';
    return returnAns;
}
char* getPermutation(int n, int k) {
    k = k - 1;
    int indexArray[n];
    int index = 0 ;
    for(int i = n ; i >0 ; i --){
        if(k >= factorial[i-1]){
            indexArray[index] = (k/factorial[i-1])+1;
            if(indexArray[index] > 0){
                k = k - (indexArray[index]-1)*factorial[i-1];
            }
        }else{
            indexArray[index] = 1;
        }
        index ++;
    }
    indexArray[n-1] = 1;
//    for(int i = 0 ; i < n ; i ++){
//        printf("%d ", indexArray[i]);
//    }
    char *returnAns = indexToString(indexArray, n);
    //printf("\n%s\n", returnAns);
    return returnAns;
}

int main()
{
    char *str = getPermutation(4,9);
    printf("%s\n", str);
    return 0;
}

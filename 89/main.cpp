#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int lowbit(int a){
    return a&-a;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int num = (int)pow(2, n);
    int *pstVector = (int *)malloc(sizeof(int)*num);

    int i = 0;
    pstVector[i ++] = 0;
    while(i <= num){
        pstVector[i] = pstVector[i-1] ^ 1;
        i ++;
        pstVector[i] = pstVector[i-1] ^ (lowbit(pstVector[i-1]) << 1);
        i ++;
    }
    (*returnSize) = num;
    return pstVector;
}

int main(){
    int cnt = 0;
    int *ans = grayCode(0, &cnt);
    for(int i = 0 ; i < cnt ; i ++){
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}

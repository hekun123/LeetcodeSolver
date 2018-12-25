#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **ans;
int cnt;

void dfs(int *nums, int numsSize, int *visit, int *tmp, int step) {
    if(step == numsSize){
        cnt ++;
        ans = (int **)realloc(ans, sizeof(int **)*cnt);
        ans[cnt-1] = (int *)malloc(sizeof(int)*numsSize);
        memcpy(ans[cnt-1], tmp, sizeof(int)*numsSize);
    }
    int i;
    for(i = 0 ; i < numsSize; i ++){
        if(!visit[i]) {
            visit[i] = 1;
            tmp[step] = nums[i];
            dfs(nums, numsSize, visit, tmp, step+1);
            visit[i] = 0;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize) {
    ans = NULL;
    cnt = 0;
    int *tmp = (int *)malloc(sizeof(int)*numsSize);
    int *visit = (int *)malloc(sizeof(int )*numsSize);
    memset(visit, 0, sizeof(int )*numsSize);
    dfs(nums, numsSize, visit, tmp, 0);
    *returnSize = cnt;
    return ans;
}

int main(){
    int a[] = {1,2,3,4};
    int cnt;
    int **ans = permute(a, 4, &cnt);
    for(int i = 0 ; i < cnt ; i ++){
        for(int j = 0 ; j < 4 ;j ++){
            printf("%d,", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

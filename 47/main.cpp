#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **ans;
int cnt;

void dfs(int *nums, int maxNum, int numsSize, int *visit, int *tmp, int step) {
    if(step == numsSize){
        cnt ++;
        ans = (int **)realloc(ans, sizeof(int **)*cnt);
        ans[cnt-1] = (int *)malloc(sizeof(int)*numsSize);
        memcpy(ans[cnt-1], tmp, sizeof(int)*numsSize);
    }
    int i;
    int visit_1[maxNum+1];
    int visit_2[maxNum+1];
    memset(visit_1, 0, sizeof(visit_1));
    memset(visit_2, 0, sizeof(visit_2));
    for(i = 0 ; i < numsSize; i ++){
        if(!visit[i]) {
            visit[i] = 1;
            if(nums[i] < 0){
                if(!visit_2[-1*nums[i]]){
                    visit_2[-1*nums[i]] = 1;
                    tmp[step] = nums[i];
                    dfs(nums, maxNum, numsSize, visit, tmp, step+1);
                }
            }else{
                if(!visit_1[nums[i]]){
                    visit_1[nums[i]] = 1;
                    tmp[step] = nums[i];
                    dfs(nums, maxNum, numsSize, visit, tmp, step+1);
                }
            }
            visit[i] = 0;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int** permuteUnique(int* nums, int numsSize, int* returnSize) {

    int maxNum = -1, i;
    for(i = 0 ; i < numsSize ; i ++) {
        if(abs(nums[i]) > maxNum){
            maxNum = nums[i];
        }
    }
    ans = NULL;
    cnt = 0;
    int *tmp = (int *)malloc(sizeof(int)*numsSize);
    int *visit_1 = (int *)malloc(sizeof(int )*numsSize);
    memset(visit_1, 0, sizeof(int )*numsSize);

    dfs(nums, maxNum, numsSize, visit_1, tmp, 0);
    *returnSize = cnt;
    return ans;
}

int main(){
    int a[] = {0, 1};
    int cnt;
    int **ans = permuteUnique(a, 2, &cnt);
    for(int i = 0 ; i < cnt ; i ++){
        for(int j = 0 ; j < 2 ;j ++){
            printf("%d,", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

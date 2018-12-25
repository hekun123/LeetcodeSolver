#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <malloc.h>


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i, cnt;
    qsort(nums, numsSize, sizeof(int), cmp);

    cnt = 0;
    int **returnArray = NULL;
    for(i = 0 ; i < numsSize ; i ++){
        if(i>0 && nums[i] == nums[i-1])continue;
        int start = i + 1;
        int end = numsSize-1;
        int ans;
        while(start < end){
            ans = nums[i] + nums[start] + nums[end];
            if(ans == 0){
                cnt ++;
                returnArray = (int **)realloc(returnArray, sizeof(int *) * cnt);
                returnArray[cnt-1] = (int *)malloc(sizeof(int ) * 3);
                returnArray[cnt-1][0] = nums[i];
                returnArray[cnt-1][1] = nums[start];
                returnArray[cnt-1][2] = nums[end];

                while(start<end && nums[start] == nums[start+1]){
                    start ++;
                }
                while(start<end && nums[end] == nums[end-1]){
                    end --;
                }
                start ++;end --;
            }else if(ans < 0){
                start ++;
            }else{
                end --;
            }

        }
    }
    *returnSize = cnt;
    return returnArray;
}

int main()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    int ans_num = 0;
    int **ans = threeSum(a, 6, &ans_num);
    for(int i = 0 ; i < ans_num ; i ++){
        printf("%d\t%d\t%d\n", ans[i][0], ans[i][1], ans[i][2]);
    }
    return 0;
}

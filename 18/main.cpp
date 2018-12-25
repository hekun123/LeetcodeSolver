#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, cnt;
    qsort(nums, numsSize, sizeof(int), cmp);

    cnt = 0;
    int **returnArray = NULL;
    for(i = 0 ; i < numsSize ; i ++){
        if(i>0 && nums[i] == nums[i-1])continue;
        int ans = target - nums[i];

        for(j = i + 1 ; j < numsSize ; j ++){

            if(j>i+1 && nums[j] == nums[j-1])continue;
            int start = j + 1;
            int end   = numsSize - 1;

            while(start < end){
                int tem_ans = nums[j] + nums[start] + nums[end];
                if(tem_ans == ans){
                    cnt ++;
                    returnArray = (int **)realloc(returnArray, sizeof(int *) * cnt);
                    returnArray[cnt-1] = (int *)malloc(sizeof(int ) * 5);
                    returnArray[cnt-1][0] = nums[i];
                    returnArray[cnt-1][1] = nums[j];
                    returnArray[cnt-1][2] = nums[start];
                    returnArray[cnt-1][3] = nums[end];

                    while(start<end && nums[start] == nums[start+1]){
                        start ++;
                    }
                    while(start<end && nums[end] == nums[end-1]){
                        end --;
                    }
                    start ++;end --;
                }else if(tem_ans < ans){
                    start ++;
                }else{
                    end --;
                }
            }
        }
    }
    *returnSize = cnt;
    return returnArray;
}

int main(){

    int nums[] = {-1,-5,-5,-3,2,5,0,4};
    int ans_len = 0;
    int **returnArray = NULL;
    returnArray = fourSum(nums, 8, -7, &ans_len);
    for(int i = 0 ; i < ans_len ; i ++){
        printf("%d\t%d\t%d\t%d\n", returnArray[i][0], returnArray[i][1], returnArray[i][2], returnArray[i][3]);
    }
}


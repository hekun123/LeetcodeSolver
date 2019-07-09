#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jump(int* nums, int numsSize) {
    int i, j, step;
    int dp[numsSize];
    memset(dp, 0x3f3f, sizeof(dp));

    dp[0] = 0;
    for(i = 0 ; i < numsSize-1; i ++) {
        step = nums[i];
        for(j = i+1 ; j <= i+step && j < numsSize; j ++) {
            if(dp[j] > dp[i]+1){
                dp[j] = dp[i] + 1;
            }
        }
    }
    return dp[numsSize-1];
}

int main() {
    int a[] ={2,3,1,1,4};
    printf("%d\n", jump(a, 5));
    return 0;
}

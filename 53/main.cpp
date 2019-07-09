#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b){
    return a>b?a:b;
}

int maxSubArray(int* nums, int numsSize) {

    int maxAns = -2147483648;
    int tmpAns = 0;
    int i;
    for(i = 0 ; i < numsSize; i ++){
        tmpAns += nums[i];
        if(i != numsSize-1 && nums[i+1] < 0){
            maxAns = max(maxAns, tmpAns);
        }
        if(i == numsSize-1){
            maxAns = max(maxAns, tmpAns);
        }
        if(tmpAns < 0){
            maxAns = max(maxAns, tmpAns);
            tmpAns = 0;
        }
    }
    return maxAns;
}

int main()
{
    int nums[] = {-2147483647};
    printf("%d\n", maxSubArray(nums, 1));
    printf("%d\n", -2147483647);
    return 0;
}

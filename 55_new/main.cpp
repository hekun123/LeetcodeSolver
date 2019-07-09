#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool canJump(int* nums, int numsSize) {
    int i, leftMostGoodPosition;
    leftMostGoodPosition = numsSize-1;
    for(i = numsSize - 2; i >= 0 ; i --){
        if(nums[i]+i >= leftMostGoodPosition){
            leftMostGoodPosition = i;
        }
    }
    return leftMostGoodPosition == 0?true:false;
}

int main(){
    int nums[] = {0};
    printf("%s\n", canJump(nums, 1)?"yes":"no");
    return 0;
}

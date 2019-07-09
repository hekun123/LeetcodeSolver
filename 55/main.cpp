#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool canJump(int* nums, int numsSize) {
    if(numsSize <= 1)return true;
    int i, j;
    int zeroFlag[numsSize], zeroNum = 0, flag;
    for(i = 0 ; i < numsSize ; i ++){
        if(nums[i] == 0){
            zeroFlag[zeroNum ++] = i;
        }
    }
    flag = 1;
    for(i = 0 ; i < zeroNum; i ++){
        flag = 0;
        for(j = zeroFlag[i]-1; j >= 0 ; j --){
            if(nums[j] > (zeroFlag[i]-j)){
                flag  = 1;
                continue;
            }
            if(zeroFlag[i] == numsSize-1 && nums[j] >= (zeroFlag[i]-j)){
                flag = 1;
                continue;
            }
        }
        if(flag == 0){
            break;
        }
    }
    return flag;
}

int main(){
    int nums[] = {2,0,0};
    printf("%s\n", canJump(nums, 3)?"yes":"no");
    return 0;
}

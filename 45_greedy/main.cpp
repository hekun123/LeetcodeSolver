#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jump(int* nums, int numsSize) {
    if(numsSize <= 1){
        return 0;
    }
    int i, step, next, temp;
    i = 0;
    step = 1;
    next = nums[0];
    while(i < numsSize){
        if(next >= numsSize-1)break;
        for (temp = i + 1; temp <= i + nums[i] && temp < numsSize; temp ++) {
            if(temp+nums[temp] > next+nums[next]){
                next = temp;
            }
        }
        step += 1;
        i = next;
        next = next + nums[i];
    }
    return step;
}

int main() {
    int a[] ={};
    printf("%d\n", jump(a, sizeof(a)/sizeof(int)));
    return 0;
}

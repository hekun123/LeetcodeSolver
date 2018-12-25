#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
    int p;
    p = *a;
    *a = *b;
    *b = p;
}

int firstMissingPositive(int* nums, int numsSize) {
    int i, ptr;
    for(i = 0 ; i < numsSize; i ++){
        if(nums[i] > 0 && nums[i] <= numsSize){
            ptr = i;
            while( (nums[ptr]-1 > i) && (nums[ptr] != nums[nums[ptr]-1]) &&
                  (nums[nums[ptr]-1] > 0) && (nums[nums[ptr]-1] <= numsSize)){
                swap(&nums[ptr], &nums[nums[ptr]-1]);
            }
            nums[nums[ptr]-1] = nums[ptr];
        }
    }
    for(i = 0; i < numsSize; i ++){
        if(i != nums[i]-1){
            return i+1;
        }
    }
    return numsSize+1;
}

int main() {
    int a[] = {7,8,9,11,12};
    int ans = firstMissingPositive(a, 5);
    printf("%d\n", ans);
    return 0;
}

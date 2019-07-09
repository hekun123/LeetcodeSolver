#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchInsert(int* nums, int numsSize, int target) {
    if(target < nums[0])return 0;
    if(target > nums[numsSize-1])return numsSize;
    int low = 0, high = numsSize-1, mid;
    while(low+1 < high){
        mid = (low+high)/2;
        if(nums[mid] == target)return mid;
        if(nums[mid] < target){
            low = mid;
        }else {
            high = mid;
        }
    }
    if(nums[low] == target)return low;
    if(nums[high] == target)return high;
    return high;
}

int main() {
    int a[] = {1,3,5,6};
    printf("%d\n", searchInsert(a, 4, 0));
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool binSearch(int *nums, int start, int end, int target){
    int left, right, mid;
    left = start;
    right = end;
    while(left <= right){
        mid = (left + right) / 2;

        if(nums[mid] == target){
            return true;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return false;
}

bool search(int* nums, int numsSize, int target) {
    int maxIndex = 0;
    for(int i = 1 ; i < numsSize; i ++){
        if(nums[i] < nums[i-1]){
            maxIndex = i;
            break;
        }
    }
    return binSearch(nums, 0, maxIndex-1, target) | binSearch(nums, maxIndex, numsSize-1, target);
}

int main(){
    int a[] = {1};
    printf("%s\n", search(a, sizeof(a)/sizeof(a[0]), 0)?"YES":"NO");
    return 0;
}

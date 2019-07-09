#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bin_search(int *nums, int low, int high, int target){
    int mid;
    while(low+1<high){
        mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] < target){
            low = mid;
        }else{
            high = mid;
        }
    }
    if(nums[high] == target)return high;
    if(nums[low] == target)return low;
    return -1;
}

int search(int* nums, int numsSize, int target) {
    int ans = -1;
    int low = 0, high = numsSize-1, mid = -1;
    while(low+1 < high){
        mid = (low+high)/2;
        if(nums[low] < nums[mid]){
            low = mid;
        }else{
            high = mid;
        }
    }
    int min_pos = nums[high]>nums[low]?low:high;
    if(nums[0] <= target && target <= nums[min_pos-1]){
        ans = bin_search(nums, 0, min_pos-1, target);
    }else{
        ans = bin_search(nums, min_pos, numsSize-1, target);
    }
    return ans;
}

int main(){
    int a[] = {5,6,-2,-1,0,1,2,3,4};
    int n = 9;
    printf("%d\n", search(a, n, 0));
    return 0;
}

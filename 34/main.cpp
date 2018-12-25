#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bin_search(int *nums, int numsSize, int target){
    int low = 0, high = numsSize-1, mid;
    while(low+1 < high) {
        mid = (low+high)/2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] < target) {
            low = mid;
        }else {
            high = mid;
        }
    }
    if(nums[low] == target)return low;
    if(nums[high] == target)return high;
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int) * 10);;
    int search_i = bin_search(nums, numsSize, target);
    if(search_i == -1){
        *returnSize = 2;
        ans[0] = -1; ans[1] = -1;
        return ans;
    }
    int start = search_i, end = search_i, i;
    while(start != 0 && nums[start-1] == target){
        start --;
    }
    while(end != numsSize-1 && nums[end+1] == target){
        end ++;
    }

    *returnSize = 2;
    ans[0] = start;
    ans[1] = end;
    return ans;
}

int main() {
    int a[] = {0,1,1,1,1,2,2,2,3,3,3,3,4,5,6,6,8,9,9,9};
    int n = 10;
    int ans_len;
    int *ans = searchRange(a, n, 0, &ans_len);
    for(int i = 0 ; i < ans_len ; i ++){
        printf("%d\t", ans[i]);
    }
    printf("\n");
    return 0;
}

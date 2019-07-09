#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val) {
    if(numsSize == 0)return 0;
    int start = 0, end = numsSize - 1;
    while(start < end){
        if(nums[start] == val){
            if(nums[end] != val){
                nums[start ++] = nums[end --];
            }else{
                end --;
            }
        }else{
            start ++;
        }
    }
    if(nums[end] == val) end --;
    return end+1;
}

int main(){
    int a[] = {0,1,2,2,3,0,4,2};
    int ans_len = removeElement(a, 8, 2);
    for(int i = 0 ; i < ans_len ; i ++){
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}


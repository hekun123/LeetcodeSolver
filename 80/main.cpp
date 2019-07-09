#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
    if(numsSize <= 1){
        return numsSize;
    }
    int cnt = 1 ;
    int flag = 0;
    for(int i = 1; i < numsSize ; i ++){
        if(nums[i] == nums[i-1]){
            if(flag){
                continue;
            }else{
                nums[cnt ++] = nums[i];
                flag = 1;
            }
        }else{
            nums[cnt ++] = nums[i];
            flag = 0;
        }
    }
    return cnt;
}

int main(){
    int cnt = 0;
    int a[] = {};
    cnt = removeDuplicates(a, sizeof(a)/sizeof(a[0]));
    for(int i = 0 ; i < cnt ; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

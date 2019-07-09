#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exchange(int *a, int *b){
    int p;
    p = *a;
    *a = *b;
    *b = p;
}

void reverse_list(int *a, int len){
    int i;
    for(i = 0 ; i < len/2; i ++){
        exchange(&a[i], &a[len-i-1]);
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i, j, flag = 0;
    for(i = numsSize-1 ; i > 0; i --) {
        if(nums[i] > nums[i-1]) {
            int min_bigger = 0x3f3f;
            int min_i = 0;
            for(j = i ; j < numsSize ; j ++) {
                if(j != numsSize-1 && nums[j] == nums[j+1])continue;
                if( nums[j] > nums[i-1]){
                    if((nums[j]-nums[i-1]) < min_bigger){
                        min_bigger = nums[j] - nums[i-1];
                        min_i = j;
                    }
                }
            }
            exchange(&nums[i-1], &nums[min_i]);
            reverse_list(nums+i, numsSize-i);
            flag = 1;
            break;
        }
    }
    if(!flag) {
        reverse_list(nums, numsSize);
    }
}

int main(){
    int a[] ={2,3,1,3,3} ;
    int n = 5;
    nextPermutation(a, n);
    for(int i = 0 ; i < n; i ++){
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}

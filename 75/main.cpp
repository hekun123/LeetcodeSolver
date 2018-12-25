#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int num = *a;
    *a = *b;
    *b = num;
}

void sortColors(int* nums, int numsSize) {
    int ptr_a = 0;
    int ptr_b = numsSize-1;
    while(ptr_a < numsSize){
        if(nums[ptr_a] == 1){
            break;
        }
        ptr_a ++;
    }

    while(ptr_b >= 0){
        if(nums[ptr_b] != 2){
            break;
        }
        ptr_b --;
    }

    int i = 0;
    while(i < numsSize){
        if(i > ptr_a && nums[i] == 0){
            swap(&nums[i], &nums[ptr_a]);
            while(ptr_a < numsSize){
                if(nums[ptr_a] == 1){
                    break;
                }
                ptr_a ++;
            }
            continue;
        }
        if(i < ptr_b && nums[i] == 2){
            swap(&nums[i], &nums[ptr_b]);
            while(ptr_b >= 0){
                if(nums[ptr_b] != 2){
                    break;
                }
                ptr_b --;
            }
            if(i < ptr_a && nums[i] == 1){
                ptr_a = i;
            }
            continue;
        }
        i ++;
    }
}

int main()
{
    int a[] = {2,2,1,1,1,1};
    int n = 6;
    sortColors(a, n);
    for(int i = 0 ; i < n ; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

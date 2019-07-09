#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0)return 0;
    int cnt = 1, i;
    int min_id = 0;
    for(i = 1 ; i < numsSize ; i ++){
        if(nums[i] == nums[i-1]){
            continue;
        }else{
            nums[++min_id] = nums[i];
            cnt ++;
        }
    }
    return cnt;
}

int main(){
    int a[] = {0,0,1,1,1,2,2,3,3,4};
    int num_len = removeDuplicates(a, 0);
    printf("%d\n", num_len);
    for(int i = 0 ; i < num_len ; i ++){
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}

#include <string.h>
#include <malloc.h>
#include <stdio.h>


int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i;
    int minNum = 0x3f3f3f;
    int returnNum = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(i = 0 ; i < numsSize ; i ++){
        int start = i + 1;
        int end   = numsSize - 1;

        while(start < end){

            int ans = target - (nums[i] + nums[start] + nums[end]);
            if(minNum > abs(ans)){
                minNum = abs(ans);
                returnNum = nums[i] + nums[start] + nums[end];
//                while(start < end && nums[start] == nums[start+1]){
//                    start ++;
//                }
//                while(start < end && nums[end] == nums[end-1]){
//                    end --;
//                }
            }
            if(ans < 0){
                end --;
            }else{
                start ++;
            }
        }
    }
    return returnNum;
}

int main()
{
    int a[] = {13,2,0,-14,-20,19,8,-5,-13,
                -3,20,15,20,5,13,14,-17,-7,12,
                -6,0,20,-19,-1,-15,-2,8,-2,-9,
                13,0,-3,-18,-9,-9,-19,17,-14,-19,
                -4,-16,2,0,9,5,-7,-4,20,18,
                9,0,12,-1,10,-17,-11,16,-13,-14,
                -3,0,2,-18,2,8,20,-15,3,-13,-12,-2,
                -19,11,11,-10,1,1,-10,-2,12,0,17,
                -19,-7,8,-19,-17,5,-5,-10,8,0,-12,
                4,19,2,0,12,14,-9,15,7,0,-16,-5,16,
                -12,0,2,-16,14,18,12,13,5,0,5,6};

    printf("%d\n", sizeof(a)/sizeof(int));
    int ans = threeSumClosest(a, sizeof(a)/sizeof(int), -59);

    printf("%d\n", ans);
    return 0;
}

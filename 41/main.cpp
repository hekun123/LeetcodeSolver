#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstMissingPositive(int* nums, int numsSize) {
    if(numsSize <= 0)return 1;
    int i;
    int vis_size = -1;
    for(i = 0 ; i < numsSize ;i ++){
        if(vis_size < nums[i])vis_size = nums[i];
    }
    if(vis_size <= 0)return 1;
    int visit[vis_size+1];
    memset(visit, 0, sizeof(visit));
    for(i = 0 ; i < numsSize; i ++){
        if(nums[i] <= 0)continue;
        visit[nums[i]] = 1;
    }
    for(i = 1 ; i < vis_size; i ++){
        if(visit[i] == 0){
            return i;
        }
    }
    return vis_size+1;
}

int main() {
    int a[] = {-1};
    printf("%d\n", firstMissingPositive(a, 1));
    return 0;
}

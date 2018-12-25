#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1, mid;
    bool found = false;
    while(l<=r){
        mid = (l+r)/2;
        if(nums[mid] == target){
            found = true;
            break;
        }
        if(nums[mid] < target){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    if(!found) return {-1,-1};
    l = mid;
    r = mid;
    while(nums[l] == target && l >= 0) l--;
    while(nums[r] == target && r <= nums.size()-1) r++;
    return {l+1,r-1};

}

void binPrint(int num){
    for(int i = 0 ; i < 8 ; i ++){
        if(num&1){
            printf("1");
        }else{
            printf("0");
        }
        num = num >> 1;
    }
    printf("\n");
}

int main()
{
    int i;
    for(i = 0 ; i < 256; i ++){
        binPrint(i);
    }
    return 0;
}

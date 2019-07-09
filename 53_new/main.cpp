#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        register int maxsum = nums[0];
        register int prevsum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            prevsum = std::max(nums[i], prevsum + nums[i]);
            maxsum = std::max(maxsum, prevsum);
        }

        return maxsum;
}

int main()
{
    int a[10] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> b(a, a+9);

    printf("%d\n", maxSubArray(b));
    printf("%d\n", -2147483647);
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int Max(int a, int b){
        return a>b?a:b;
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 0){
            return 0;
        }
        int i_dp[(int)nums.size()];
        for(int i = 0 ;i  < nums.size(); ++ i){
            i_dp[i] = 1;
            for(int j = i-1 ; j >= 0 ; -- j){
                if(nums[j] < nums[i]){
                    i_dp[i] = Max(i_dp[i], i_dp[j]+1);      
                }
            }
        }
        int i_MaxLen = -1;
        for(int i = 0 ; i < nums.size() ;++ i){
            i_MaxLen = Max(i_MaxLen, i_dp[i]);
        }
        return i_MaxLen;
    }
};


int main(){
    Solution a;
    vector<int> vNums;
    vNums.push_back(10);
    vNums.push_back(9);
    vNums.push_back(2);
    vNums.push_back(5);
    vNums.push_back(3);
    vNums.push_back(7);
    vNums.push_back(101);
    vNums.push_back(18);
    printf("%d\n", a.lengthOfLIS(vNums));
    return 0;
}
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <utility> 
#include<unordered_set>
#include<numeric>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int m = nums.size();
        int x = accumulate(nums.begin(),nums.end(),-target);
        if(x&1||x<0)return 0;
        x = x/2;
        vector<vector<int>> dp(m+1,vector<int>(x+1));
        dp[0][0] = 1;
        for(int i = 1;i<=m;++i){
            for(int j = 0;j<=x;++j){
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i-1]){
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[m][x];
    }
};
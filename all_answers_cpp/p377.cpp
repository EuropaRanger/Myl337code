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
    int combinationSum4(vector<int>& nums, int target) {
        int m = nums.size();
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int j = 0;j<=target;++j){
            for(int i = 1;i<=m;++i){
                if(j<nums[i-1]||INT_MAX-dp[j-nums[i-1]]<dp[j])continue;
                dp[j] = dp[j]+dp[j-nums[i-1]];
            }
        }
        return dp[target];
    }
};
#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stk;
        stk.push(0);
        for(int i = 1;i<nums.size();++i){
            if(nums[stk.top()]>nums[i]){
                stk.push(i);
            }
        }
        int ans = 0;
        for(int i = nums.size()-1;i>=0;--i){
            while(nums[stk.top()]<=nums[i]){
                ans = ans>i-stk.top()?ans:i-stk.top();
                stk.pop();
                if(stk.empty()){
                    goto a;
                }
            }
        }
        a:
        return ans;
    }
};
#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmin(n);
        vector<int> rightmin(n);
        vector<long long> prefsum(n+1);
        prefsum[0] = 0;
        for(int i = 1;i<=n;++i){
            prefsum[i+1] = prefsum[i]+nums[i];
        }
        stack<int> stk;
        for(int i = 0;i<n;++i){
            while(!stk.empty()&&nums[stk.top()]>=nums[i]){
                stk.pop();
            }
            leftmin[i] = stk.empty()?-1:stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = n-1;i>=0;--i){
            while(!stk.empty()&&nums[stk.top()]>=nums[i]){
                stk.pop();
            }
            rightmin[i] = stk.empty()?n:stk.top();
            stk.push(i);
        }
        long long res = 0LL;
        for(int i = 0;i<n;++i){
            long long prod = (prefsum[rightmin[i]]-prefsum[leftmin[i]+1])*nums[i];
            res = res>=prod?res:prod;
        }
        return res%(1000000000+7);
    }
};
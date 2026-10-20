#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q{0};
        vector<int> fRes(n);
        fRes[0] = 0;
        int ans = INT_MIN;
        for(int i = 0;i<n;++i){
            while(i-q.front()>k){
                q.pop_front();
            }
            fRes[i] = max(0,fRes[q.front()])+nums[i];
            ans = max(ans,fRes[i]);
            while(q.size()&&fRes[q.back()]<=fRes[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans;
    }
};
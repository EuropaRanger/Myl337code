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
    int shortestSubarray(vector<int>& nums, int k) {
        int front = 0;
        int back = 0;
        int n = nums.size();
        deque<int> q;
        vector<int> prefsum(n+1);
        for(int i =0;i<n;i++){
            prefsum[i+1] = prefsum[i]+nums[i];
        }
        int res = n+1;
        for(int i = 0;i<=n;++i){
            while(q.size()&&prefsum[i]-prefsum[q.front()]>=k){
                res = min(res,i-q.front());
                q.pop_front();
            }
            while(q.size()&&prefsum[i]<=prefsum[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        if(res==n+1){
            return -1;
        }
        return res;
    }
};
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
    bool canPartition(vector<int>& nums) {
        int m = nums.size();
        int x = accumulate(nums.begin(),nums.end(),0);
        if(x&1)return false;
        x /= 2;
        vector<char> cur(x+1);
        vector<char> next(x+1);
        cur[0] = '1';
        for(int i = 1;i<=m;++i){
            if(nums[i-1]>x)return false;
            for(int j = 0;j<=x;++j){
                if(j<nums[i-1]){
                    next[j] = cur[j];
                }else{
                    next[j] = cur[j]||cur[j-nums[i-1]];
                }
            }
            swap(cur,next);
        }
        return cur[x];
    }
};
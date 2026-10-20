#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        auto getMaxSum = [&](){
            stack<int> stkl;
            vector<int> left(n);
            stack<int> stkr;
            vector<int> right(n);
            for(int i = n-1;i>=0;--i){
                while(!stkr.empty()&&nums[stkr.top()]<=nums[i]){
                    stkr.pop();
                }
                right[i] = stkr.empty()?n-i:stkr.top()-i;
                stkr.push(i);
            }
            for(int i = 0;i<n;++i){
                while(!stkl.empty()&&nums[stkl.top()]<nums[i]){
                    stkl.pop();
                }
                left[i] = stkl.empty()?i+1:i-stkl.top();
                stkl.push(i);
            }
            long long ans = 0;
            for(int i = 0;i<n;++i){
                ans+=1LL * left[i]*right[i]*nums[i];
            }
            return ans;
        };
        long long res = getMaxSum();
        for(int i = 0;i<n;++i){
            nums[i] *= -1;
        }
        res += getMaxSum();
        return res;
    }
};
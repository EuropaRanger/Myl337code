#include <vector>
#include <string>
#include <functional>
#include <utility> 
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int start = 0;
        int res = 0;
        for(int cur = 1;cur<=nums.size();++cur){
            product *= nums[cur-1];
            while(product>=k&&start<cur){
                product/=nums[start];
                ++start;
            }
            res+= cur-start;
        }
        return res;
    }
};
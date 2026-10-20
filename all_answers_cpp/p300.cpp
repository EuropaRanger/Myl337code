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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> table(n,0);
        int addI = 0;
        for(int i = n-1;i>=0;--i){
            addI = -1;
            for(int j = i+1;j<n;++j){
                if(nums[j]>nums[i]){
                    if(addI==-1){
                        addI=j;
                    }else{
                        addI = table[addI]>=table[j]?addI:j;
                    }
                }
            }
            if(addI==-1){
                table[i]=1;
            }else{
                table[i] = 1+table[addI];
            }
        }
        int res = 0;
        for(int i = 0;i<n;++i){
            res = max(res,table[i]);
        }
        return res;
    }
};
#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int,int> res;
        for(int i = nums2.size()-1;i>=0;--i){
            while(!stk.empty()&&stk.top()<nums2[i]){
                stk.pop();
            }
            if(!stk.empty()){
                res[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
        }
        vector<int> ans;
        for(int i = 0;i<nums1.size();++i){
            ans.push_back(res.find(nums1[i])!=res.end()?res[nums1[i]]:-1);
        }
        return ans;
    }
};
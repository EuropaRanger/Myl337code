#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size());
        for(int i=temperatures.size()-1;i>=0;--i){
            while(!stk.empty()&&temperatures[stk.top()]<=temperatures[i]){
                stk.pop();
            }
            res[i] = stk.empty()?0:stk.top()-i;
            stk.push(i);
        }
        return res;
    }
};
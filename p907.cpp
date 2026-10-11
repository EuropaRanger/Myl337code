#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> rightMin(arr.size());
        vector<int> leftMin(arr.size());
        stack<int> stk;
        for(int i = 0;i<arr.size();++i){
            while(!stk.empty()&&arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            leftMin[i] = stk.empty()?i+1:i-stk.top();
            stk.push(i);
        }
        stack<int> stk2;
        for(int i = arr.size()-1;i>=0;--i){
            while(!stk2.empty()&&arr[stk2.top()]>arr[i]){
                stk2.pop();
            }
            rightMin[i] = stk2.empty()?arr.size()-i:stk2.top()-i;
            stk2.push(i);
        }
        long long sum = 0;
        const int mod = 1e9 + 7;
        for(int i=0;i<arr.size();++i){
            sum+= 1LL * arr[i]*leftMin[i]*rightMin[i] % mod;
            sum%= mod;
        }
        return sum;
    }
};
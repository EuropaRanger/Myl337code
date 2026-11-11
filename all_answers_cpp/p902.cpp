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
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int m = s.size();
        vector<int> dp(m,-1);
        function<int(int,bool,bool)> dfs = [&](int i,bool lead,bool limit)->int{
            if(i>=m)return lead?0:1;
            if(!lead&&!limit&&dp[i]!=-1)return dp[i];
            int ans = 0;
            if(lead)ans+=dfs(i+1,true,false);
            for(string cur:digits){
                if(cur[0]>s[i]&&limit)break;
                if(cur[0]==s[i]&&limit){
                    ans+=dfs(i+1,false,true);
                    break;
                }else{
                    ans+=dfs(i+1,false,false);
                }
            }
            if(!lead&&!limit)dp[i] = ans;
            return ans;
        };
        return dfs(0,true,true);
    }
};
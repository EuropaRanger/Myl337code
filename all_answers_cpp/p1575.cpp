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
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        const int mod = 1e9+7;
        vector<int> least_f(n);
        for(int i = 0;i<n;++i){
            least_f[i] = abs(locations[i]-locations[finish]);
        }
        vector<vector<int>> dp(n,vector<int>(fuel+1,-1));
        function<void(int,int)> dfs = [&](int index,int oil){
            if(least_f[index]>oil){
                dp[index][oil] = 0;
                return;
            }
            dp[index][oil] = index==finish;
            for(int i = 0;i<n;++i){
                if(i==index)continue;
                int cost = abs(locations[i]-locations[index]);
                if(oil<cost)continue;
                if(dp[i][oil-cost]==-1)dfs(i,oil-cost);
                dp[index][oil]=(dp[index][oil]+dp[i][oil-cost])%mod;
            }
        };
        dfs(start,fuel);
        return dp[start][fuel];
    }
};
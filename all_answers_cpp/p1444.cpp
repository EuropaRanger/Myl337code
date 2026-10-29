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
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(),n = pizza[0].size();
        const int mod = 1e9+7;
        vector<vector<int>> pref(m+1,vector<int>(n+1));
        for(int i = m-1;i>=0;--i){
            for(int j = n-1;j>=0;--j){
                pref[i][j]=pref[i+1][j]+pref[i][j+1]-pref[i+1][j+1]+(pizza[i][j]=='A');
            }
        }
        if(k==1&&pref[0][0]==0)return 0;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k)));
        dp[0][0][k-1] = 1;
        for(int cut = k-1;cut>0;--cut){
            for(int i = 0;i<m;++i){
                for(int j = 0;j<n;++j){
                    if(dp[i][j][cut]==0)continue;
                    for(int col = j+1;col<n;++col){
                        if(pref[i][j]-pref[i][col]<=0)continue;
                        if(pref[i][col]<cut)continue;
                        dp[i][col][cut-1]=(dp[i][j][cut]+dp[i][col][cut-1])%mod;
                    }
                    for(int row = i+1;row<m;++row){
                        if(pref[i][j]-pref[row][j]<=0)continue;
                        if(pref[row][j]<cut)continue;
                        dp[row][j][cut-1]=(dp[i][j][cut]+dp[row][j][cut-1])%mod;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                ans= (ans+dp[i][j][0])%mod;
            }
        }
        return ans;
    }
};
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
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        const int mod = 1e9+7;
        vector<vector<int>> dp(m,vector<int>(n));
        vector<int> dir = {-1,0,1,0,-1};
        function<void(int,int)> DFS = [&](int x, int y){
            for(int k = 0;k<4;k++){
                int a = x+dir[k],b = y+dir[k+1];
                if(0<=a&&a<m&&0<=b&&b<n&&grid[a][b]>grid[x][y]){
                    if(dp[a][b]==0){
                        DFS(a,b);
                    }
                    dp[x][y]=(dp[a][b]+dp[x][y])%mod;
                }
            }
            ++dp[x][y];
        };
        int ans = 0;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(dp[i][j]==0){
                    DFS(i,j);
                }
                ans = (ans+dp[i][j])%mod;
            }
        }
        return ans;
    }
};
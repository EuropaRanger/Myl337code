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
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        vector<int> dir = {-1,0,1,0,-1};
        function<void(int,int)> DFS = [&](int x,int y){
            for(int k = 0;k<4;++k){
                int a = x+dir[k],b = y+dir[k+1];
                if(0<=a&&a<m&&0<=b&&b<n&&matrix[a][b]>matrix[x][y]){
                    if(0==dp[a][b]){//因为序列严格上升，DFS不可能回到走过的格子
                        DFS(a,b);
                    }
                    dp[x][y] = max(dp[x][y],1+dp[a][b]);
                }
            }
            if(0==dp[x][y])dp[x][y] = 1;
        };
        int ans = 0;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(dp[i][j]==0){
                    DFS(i,j);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
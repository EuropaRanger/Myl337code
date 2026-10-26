#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <utility> 
#include<unordered_set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<int> dir = {-1,0,1,0,-1};
        function<int(int,int)> DFS = [&](int x,int y){
            int cur = grid[x][y];
            grid[x][y] = 0;
            int f_res = 0;
            for(int k = 0;k<4;k++){
                int a = x+dir[k],b = y+dir[k+1];
                if(0<=a&&a<m&&0<=b&&b<n&&grid[a][b]!=0){
                    f_res = max(f_res,DFS(a,b));
                }
            }
            grid[x][y] = cur;
            return f_res+cur;
        };
        int ans = 0;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(grid[i][j]!=0){
                    ans = max(DFS(i,j),ans);
                }
            }
        }
        return ans;
    }
};
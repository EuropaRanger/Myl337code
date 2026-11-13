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
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(),n = grid[0].size();
        vector<int> p(m*n+1);
        vector<int> size(m*n+1);
        for(int i = 0;i<p.size();++i){
            p[i] = i;
            size[i] = 1;
        }
        function<int(int)>find = [&](int x)->int{
            if(p[x]!=x)p[x] = find(p[x]);
            return p[x];
        };
        function<void(int,int)> merge = [&](int a,int b)->void{
            int ra = find(a),rb = find(b);
            if(ra!=rb){
                size[rb]+=size[ra];
                p[ra] = rb;
            }
        };
        for(auto& h:hits){
            if(grid[h[0]][h[1]] == 1){
                grid[h[0]][h[1]] = 0;
            }else{
                grid[h[0]][h[1]] = -1;
            }
        }
        for(int j = 0;j<n;++j){
            if(grid[0][j]==1)merge(j,m*n);
        }
        for(int i = 1;i<m;++i){
            for(int j = 0;j<n;++j){
                if(grid[i][j]!=1)continue;
                if(grid[i-1][j]==1)merge(i*n+j,(i-1)*n+j);
                if(j>0&&grid[i][j-1]==1)merge(i*n+j,i*n+j-1);
            }
        }
        vector<int> ans(hits.size());
        vector<int> dir = {0,-1,0,1,0};
        for(int k = hits.size()-1;k>=0;--k){
            int i = hits[k][0],j = hits[k][1];
            if(grid[i][j]==-1)continue;
            grid[i][j] = 1;
            int prev = size[find(m*n)];
            if(i==0)merge(j,m*n);
            for(int l = 0;l<4;++l){
                int x = i+dir[l],y = j+dir[l+1];
                if(0<=x&&x<m&&0<=y&&y<n&&grid[x][y]==1)merge(x*n+y,i*n+j);
            }
            int cur =  size[find(m*n)];
            ans[k] = max(0,cur-prev-1);
        }
        return ans;
    }
};
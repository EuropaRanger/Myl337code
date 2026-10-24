#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        deque<tuple<int,int,int>> q;
        vector<vector<char>> vis(m,vector<char>(n));
        q.push_front({0,0,0});
        vector<int> dir = {-1,0,1,0,-1};
        while(1){
            auto [a,b,d] = q.front();
            q.pop_front();
            if(a==m-1&&b==n-1){
                return d;
            }
            if(vis[a][b]=='1'){
                continue;
            }
            vis[a][b] = '1';
            for(int k = 0;k<4;++k){
                int x = a+dir[k],y = b+dir[k+1];
                if(0<=x&&x<m&&0<=y&&y<n){
                    if(grid[x][y]){
                        q.push_back({x,y,d+1});
                    }else{
                        q.push_front({x,y,d});
                    }
                }
            }
        }
    }
};
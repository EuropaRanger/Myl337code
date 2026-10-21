#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        if(k>=m+n-3)return m+n-2;
        vector<vector<vector<char>>> vis(m,vector<vector<char>>(n,vector<char>(k+1)));
        queue<tuple<int,int,int>> q;
        vector<int> dir = {-1,0,1,0,-1};
        int x,y;
        q.push({0,0,k});
        vis[0][0][k] = '1';
        for(int step=1;q.size();++step){
            for(int cur_edge = q.size();cur_edge;--cur_edge){
                auto[a,b,k]=q.front();
                q.pop();
                for(int d = 0;d<4;++d){
                    x = a+dir[d];
                    y = b+dir[d+1];
                    if(0<=x&&x<m&&y>=0&&y<n){
                        if(x==m-1&&y==n-1){
                            return step;
                        }
                        if(grid[x][y]==1){
                            if(k>0&&vis[x][y][k-1]!='1'){
                                q.push({x,y,k-1});
                                vis[x][y][k-1]='1';
                            }
                        }else{
                            if(vis[x][y][k]!='1'){
                                q.push({x,y,k});
                                vis[x][y][k] = '1';
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};
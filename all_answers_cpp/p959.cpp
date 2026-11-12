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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n));
        vector<int> dir = {0,1,0,-1,0};
        vector<char> dir_encoder = {1,2,4,8};
        int res = 0;
        for(int i = 0;i<n;++i){
            for(int j = 0;j<n;++j){
                for(int k = 0;k<4;++k){
                    if(vis[i][j]&dir_encoder[k])continue;
                    ++res;
                    queue<tuple<int,int,char>>q;
                    q.push({i,j,k});
                    vis[i][j]+=dir_encoder[k];
                    while(q.size()){
                        auto[a,b,d] = q.front();
                        q.pop();
                        if((vis[a][b]&dir_encoder[(d+7)%4])==0){
                            if(grid[a][b]==' '||(grid[a][b]=='\\'&&(d==0||d==2))||(grid[a][b]=='/'&&(d==1||d==3))){
                                q.push({a,b,(d+7)%4});
                                vis[a][b]+=dir_encoder[(d+7)%4];
                            }
                        }
                        if((vis[a][b]&dir_encoder[(d+1)%4])==0){
                            if(grid[a][b]==' '||(grid[a][b]=='/'&&(d==0||d==2))||(grid[a][b]=='\\'&&(d==1||d==3))){
                                q.push({a,b,(d+1)%4});
                                vis[a][b]+=dir_encoder[(d+1)%4];
                            }
                        }
                        int x = a+dir[d];
                        int y = b+dir[d+1];
                        if(0<=x&&x<n&&0<=y&&y<n&&(vis[x][y]&dir_encoder[(d+2)%4])==0){
                            q.push({x,y,(d+2)%4});
                            vis[x][y]+=dir_encoder[(d+2)%4];
                        }
                    }
                }
            }
        }
        return res;
    }
};
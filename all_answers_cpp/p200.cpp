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
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int count = 0;
        vector<int> dirs = {-1,0,1,0,-1};
        auto BFS=[&](int x,int y){
            ++count;
            queue<pair<int,int>> q;
            q.push({x,y});
            grid[x][y] = '0';
            while(q.size()){
                auto[a,b] = q.front();
                q.pop();
                for(int k=0;k<4;++k){
                    int cx = a+dirs[k];
                    int cy = b+dirs[k+1];
                    if(0<=cx&&cx<n&&0<=cy&&cy<m&&grid[cx][cy]=='1'){
                        grid[cx][cy]='0';
                        q.push({cx,cy});
                    }
                }
            }
        };
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(grid[i][j]=='1'){
                    BFS(i,j);
                }
            }
        }
        return count;
    }
};
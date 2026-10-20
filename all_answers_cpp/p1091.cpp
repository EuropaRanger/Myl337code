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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int count = 1;
        int n = grid.size();
        if(grid[0][0]||grid[n-1][n-1]){
            return -1;
        }
        vector<int>dir = {0,1,1,0,-1,1,-1,-1,0};
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int x,y;
        while(q.size()){
            auto[a,b] = q.front();
            q.pop();
            for(int k = 0;k<8;++k){
                x = a+dir[k];
                y = b+dir[k+1];
                if(0<=x&&x<n&&y>=0&&y<n&&!grid[x][y]){
                    grid[x][y] = grid[a][b]+1;
                    q.push({x,y});
                }
            }
        }
        if(grid[n-1][n-1]==0){
            return -1;
        }
        return grid[n-1][n-1];
    }
};
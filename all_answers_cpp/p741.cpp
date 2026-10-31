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
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1)return grid[0][0];
        vector<vector<vector<int>>> f(n,vector<vector<int>>(n,vector<int>(n+n-1,-1e9)));
        f[0][0][0] = grid[0][0];
        vector<int> dir = {0,0,-1,-1,0};
        for(int step = 1;step<n+n-1;++step){
            for(int i1 = 0;i1<n;++i1){
                for(int i2 = 0;i2<n;++i2){
                    int j1 = step-i1,j2 = step-i2;
                    if(j1<0||j1>=n||j2<0||j2>=n||grid[i1][j1]==-1||grid[i2][j2]==-1)continue;
                    for(int d = 0;d<4;++d){
                        if(i1+dir[d]>=0&&i2+dir[d+1]>=0){
                            f[i1][i2][step] = max(f[i1+dir[d]][i2+dir[d+1]][step-1],f[i1][i2][step]);
                        }
                    }
                    if(i1==i2){
                        f[i1][i2][step]+=grid[i1][j1];
                    }else{
                        f[i1][i2][step]+=grid[i1][j1]+grid[i2][j2];
                    }
                }
            }
        }
        return max(0,f[n-1][n-1][n+n-2]);
    }
};
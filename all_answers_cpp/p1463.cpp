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
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> cur(n,vector<int>(n,-1));
        vector<vector<int>> next(n,vector<int>(n,-1));
        cur[0][n-1] = grid[0][0]+grid[0][n-1];
        for(int step = 1;step<m;++step){
            for(vector<int> f:next){
                fill(f.begin(),f.end(),-1);
            }
            for(int i1 = 0;i1<n;++i1){
                for(int i2 = 0;i2<n;++i2){
                    for(int x1 = i1-1;x1<=i1+1;++x1){
                        for(int x2 = i2-1;x2<=i2+1;++x2){
                            if(0<=x1&&0<=x2&&x1<n&&x2<n){
                                next[i1][i2] = max(next[i1][i2],cur[x1][x2]);
                            }
                        }
                    }
                    if(next[i1][i2]==-1)continue;
                    if(i1==i2){
                        next[i1][i2]+=grid[step][i1];
                    }else{
                        next[i1][i2]+=grid[step][i1]+grid[step][i2];
                    }
                }
            }
            swap(next,cur);
        }
        int ans = 0;
        for(int i1 = 0;i1<n;++i1){
            for(int i2 = 0;i2<n;++i2){
                ans = max(ans,cur[i1][i2]);
            }
        }
        return ans;
    }
};
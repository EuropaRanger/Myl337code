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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n*n;
        vector<int> p(m);
        iota(p.begin(),p.end(),0);
        function<int(int)> find = [&](int x)->int{
            if(p[x]!=x)p[x] = find(p[x]);
            return p[x];
        };
        vector<int> hi(m);
        for(int i = 0;i<n;++i){
            for(int j = 0;j<n;++j){
                hi[grid[i][j]]=i*n+j;
            }
        }
        vector<int> dir = {0,1,0,-1,0};
        for(int t = 0;t<m;++t){
            int id = hi[t];
            int x = id/n,y = id%n;
            for(int k = 0;k<4;++k){
                int a = x+dir[k],b = y+dir[k+1];
                if(0<=a&&a<n&&0<=b&&b<n&&grid[a][b]<=t){
                    int p_ori = find(id);
                    int p_new = find(a*n+b);
                    p[p_new] = p_ori;
                }
            }
            if(find(0)==find(m-1))return t;
        }
        return 0;
    }
};
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
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(),m = isWater[0].size();
        vector<vector<int>> res(n,vector<int>(m));
        vector<int> dir = {-1,0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(isWater[i][j]){
                    isWater[i][j]=-1;
                    q.push({i,j});
                }
            }
        }
        int x,y;
        while(q.size()){
            auto[a,b] = q.front();
            q.pop();
            for(int k = 0;k<4;++k){
                x = a+dir[k];
                y = b+dir[k+1];
                if(0<=x&&x<n&&y>=0&&y<m&&isWater[x][y]!=-1){
                    res[x][y] = res[a][b]+1;
                    q.push({x,y});
                    isWater[x][y]=-1;
                }
            }
        }
        return res;
    }
};
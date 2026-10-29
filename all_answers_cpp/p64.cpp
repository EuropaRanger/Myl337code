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

typedef tuple<int,int,int> III;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<III,vector<III>,greater<III>> q;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<char>> fixed(m,vector<char>(n,'0'));
        dist[0][0] = grid[0][0];
        q.push({grid[0][0],0,0});
        while(q.size()){
            auto[curd,a,b] = q.top();
            if(curd>dist[a][b]||fixed[a][b] == '1')continue;
            fixed[a][b] = '1';
            q.pop();
            if(a+1<m&&fixed[a+1][b]=='0'&&curd+grid[a+1][b]<dist[a+1][b]){
                q.push({curd+grid[a+1][b],a+1,b});
                dist[a+1][b] = curd+grid[a+1][b];
            }
            if(b+1<n&&fixed[a][b+1]=='0'&&curd+grid[a][b+1]<dist[a][b+1]){
                q.push({curd+grid[a][b+1],a,b+1});
                dist[a][b+1] = curd+grid[a][b+1];
            }
        }
        return dist[m-1][n-1];
    }
};
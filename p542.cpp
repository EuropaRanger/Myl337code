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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>>res(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(!mat[i][j]){
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        vector<int> dir = {-1,0,1,0,-1};
        int cx,cy,tx,ty;
        while(q.size()){
            auto[a,b]=q.front();
            q.pop();
            for(int k = 0;k<4;++k){
                cx = a+dir[k];
                cy = b+dir[k+1];
                if(cx>=0&&cx<n&&cy>=0&&cy<m&&res[cx][cy]==-1){
                    if(mat[cx][cy]){
                        res[cx][cy] = res[a][b]+1;
                    }else{
                        res[cx][cy]=0;
                    }
                    q.push({cx,cy});
                }
            }
        }
        return res;
    }
};
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
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(),n = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        vector<int> dir = {-1,0,1,0,-1};
        int x,y;
        for(int step = 1;q.size();++step){
            for(int k = q.size();k;--k){
                auto[a,b] = q.front();
                q.pop();
                for(int d = 0;d<4;++d){
                    x = a+dir[d];
                    y = b+dir[d+1];
                    if(0<=x&&x<m&&0<=y&&y<n&&maze[x][y]=='.'){
                        maze[x][y]='+';
                        if(x==0||x==m-1||y==0||y==n-1){
                            return step;
                        }
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};
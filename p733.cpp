#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int src_clr = image[sr][sc];
        if(src_clr==color){
            return image;
        }
        int x_h = image.size();
        int y_h = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(q.size()){
            auto [x,y] = q.front();
            q.pop();
            if(x+1<x_h&&image[x+1][y]==src_clr){
                q.push({x+1,y});
                image[x+1][y]=color;
            }
            if(y+1<y_h&&image[x][y+1]==src_clr){
                q.push({x,y+1});
                image[x][y+1]=color;
                
            }
            if(x-1>=0&&image[x-1][y]==src_clr){
                q.push({x-1,y});
                image[x-1][y]=color;
            }
            if(y-1>=0&&image[x][y-1]==src_clr){
                q.push({x,y-1});
                image[x][y-1]=color;
            }
        }
        return image;
    }
};
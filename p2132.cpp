#include <vector>
#include <string>
#include <functional>
#include <utility> 
using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        vector<vector<int>> sum = grid;
        vector<vector<int>> diff(grid.size(),vector<int>(grid[0].size()));
        int a,b,c;
        for(int i = 0;i<grid.size();++i){
            for(int j = 0;j<grid[0].size();++j){
                c = i&&j?sum[i-1][j-1]:0;
                a = i?sum[i-1][j]:0;
                b = j?sum[i][j-1]:0;
                sum[i][j] += a+b-c;
            }
        }
        auto check = [&](int x, int y){
            if(x+stampHeight>grid.size()||y+stampWidth>grid[0].size()){
                return false;
            }
            int a = x&&y?sum[x-1][y-1]:0;
            int b = x?sum[x-1][y+stampWidth-1]:0;
            int c = y?sum[x+stampHeight-1][y-1]:0;
            return sum[x+stampHeight-1][y+stampWidth-1]-b-c+a==0;
        };
        for(int i = 0;i<grid.size();++i){
            for(int j = 0;j<grid[0].size();++j){
                if(check(i,j)){
                    diff[i][j]+=1;
                    if(i+stampHeight<grid.size()){
                        diff[i+stampHeight][j]-=1;
                    }
                    if(j+stampWidth<grid[0].size()){
                        diff[i][j+stampWidth]-=1;
                    }
                    if(i+stampHeight<grid.size()&&j+stampWidth<grid[0].size()){
                        diff[i+stampHeight][j+stampWidth]+=1;
                    }
                }
            }
        }
        for(int i = 0;i<grid.size();++i){
            for(int j = 0;j<grid[0].size();++j){
                c = i&&j?diff[i-1][j-1]:0;
                a = i?diff[i-1][j]:0;
                b = j?diff[i][j-1]:0;
                diff[i][j] += a+b-c;                
            }
        }
        for(int i = 0;i<grid.size();++i){
            for(int j = 0;j<grid[0].size();++j){
                if(!diff[i][j]){
                    if(!grid[i][j]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
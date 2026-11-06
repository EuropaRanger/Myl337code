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
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int m = piles.size();
        for(int i = 0;i<m;++i){
            for(int j = 1;j<piles[i].size();++j){
                piles[i][j]+=piles[i][j-1];
            }
        }
        vector<int> cur(k+1);
        vector<int> next(k+1);
        for(int i = 1;i<=m;++i){  
            for(int j = 1;j<=k;++j){
                next[j] = cur[j];
                for(int l = 0;l<piles[i-1].size()&&l<j;++l){
                    next[j] = max(next[j],cur[j-l-1]+piles[i-1][l]);
                }
            }
            swap(cur,next);
        }
        return cur[k];
    }
};
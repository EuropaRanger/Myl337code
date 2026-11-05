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
    int lastStoneWeightII(vector<int>& stones) {
        int m = stones.size();
        int x = accumulate(stones.begin(),stones.end(),0);
        int half = x>>1;
        vector<char> cur(half+1);
        vector<char> next(half+1);
        cur[0] = '0';
        for(int i = 1;i<=m;++i){
            for(int j = 0;j<=half;++j){
                if(j<stones[i-1]){
                    next[j] = cur[j];
                }else{
                    next[j] = cur[j]||cur[j-stones[i-1]];
                }
            }
            swap(next,cur);
        }
        int i_a = half;
        for(;!cur[i_a];--i_a){}
        return x-2*i_a;
    }
};
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
    int coinChange(vector<int>& coins, int amount) {
        int m = coins.size();
        vector<int> cur(amount+1,INT_MAX);
        sort(begin(coins), end(coins));
        cur[0] = 0;
        for(int i = 1;i<=m;++i){
            if(coins[i-1]>amount)break;
            for(int j = 0;j<=amount;++j){
                if(j<coins[i-1]||cur[j-coins[i-1]]==INT_MAX)continue;
                cur[j] = min(cur[j],cur[j-coins[i-1]]+1);
            }
        }
        return cur[amount]==INT_MAX?-1:cur[amount];
    }
};
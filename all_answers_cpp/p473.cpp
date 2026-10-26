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
    bool makesquare(vector<int>& matchsticks) {
        int k =4;
        int s = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (s % k) {
            return false;
        }
        s /= k;
        int n = matchsticks.size();
        vector<int> cur(k);
        function<bool(int)> dfs = [&](int i) {
            if (i == n) {
                return true;
            }
            for (int j = 0; j < k; ++j) {
                if (j && cur[j] == cur[j - 1]) {
                    continue;
                }
                cur[j] += matchsticks[i];
                if (cur[j] <= s && dfs(i + 1)) {
                    return true;
                }
                cur[j] -= matchsticks[i];
            }
            return false;
        };
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(0);
    }
};
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
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.size();
        vector<vector<int>> f(m,vector<int>(1<<10,-1));
        function<int(int,int,bool,bool)> dfs = [&](int i, int mask, bool lead, bool limit) -> int {
            if (i >= m) {
                return lead ^ 1;
            }
            if (!limit && !lead && f[i][mask] != -1) {
                return f[i][mask];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (mask >> j & 1) {
                    continue;
                }
                if (lead && j == 0) {
                    ans += dfs(i + 1, mask, true, limit && j == up);
                } else {
                    ans += dfs(i + 1, mask | (1 << j), false, limit && j == up);
                }
            }
            if (!limit && !lead) {
                f[i][mask] = ans;
            }
            return ans;
        };
        return dfs(0, 0, true, true);
    }
};
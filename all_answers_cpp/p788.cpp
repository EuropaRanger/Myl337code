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
    int rotatedDigits(int n) {
        string s = to_string(n);
        int m = s.size();
        vector<vector<int>> f(m,vector<int>(2,-1));
        function<int(int,int,bool)> dfs = [&](int i, int ok, bool limit) -> int {
            if (i >= m) {
                return ok;
            }
            if (!limit && f[i][ok] != -1) {
                return f[i][ok];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (j == 0 || j == 1 || j == 8) {
                    ans += dfs(i + 1, ok, limit && j == up);
                } else if (j == 2 || j == 5 || j == 6 || j == 9) {
                    ans += dfs(i + 1, 1, limit && j == up);
                }
            }
            if (!limit) {
                f[i][ok] = ans;
            }
            return ans;
        };
        return dfs(0, 0, true);
    }
};
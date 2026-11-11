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
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        const vector<int> dirs = {0, 1, 0, -1, 0};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j]) {
                    queue<tuple<int, int ,char>> q;
                    q.push({i, j, 5});
                    vis[i][j] = true;

                    while (!q.empty()) {
                        auto [x,y,f] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dirs[k], ny = y + dirs[k + 1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                if (grid[nx][ny] != grid[x][y] || k==f) {
                                    continue;
                                }
                                if (vis[nx][ny]) {
                                    return true;
                                }
                                q.push({nx, ny, (k+2)%4});
                                vis[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
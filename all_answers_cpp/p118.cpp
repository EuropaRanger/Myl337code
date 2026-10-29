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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        for(int i = 1;i<numRows;++i){
            res.push_back(vector<int>(1,1));
            for(int j = 0;j<res[i-1].size()-1;++j){
                res[i].push_back(res[i-1][j]+res[i-1][j+1]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};
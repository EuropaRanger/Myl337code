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
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int m = equations.size();
        vector<double> ans(queries.size(),-1.0); 
        unordered_set<string> all;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<2;++j){
                all.emplace(equations[i][j]);
            }
        }
        for(int q = 0;q<queries.size();++q){
            if(all.count(queries[q][0])==0||all.count(queries[q][1])==0)continue;
            stack<string> stk;
            unordered_map<string,double> vis;
            stk.push(queries[q][0]);
            vis.emplace(queries[q][0],1.0);
            while(stk.size()){
                string cur = stk.top();
                if(cur==queries[q][1]){
                    ans[q] = vis[cur];
                    break;
                }
                stk.pop();
                for(int i = 0;i<equations.size();++i){
                    if(equations[i][0]==cur&&vis.count(equations[i][1])==0){
                        stk.push(equations[i][1]);
                        vis.emplace(equations[i][1],vis[cur]*values[i]);
                    }
                    if(equations[i][1]==cur&&vis.count(equations[i][0])==0){
                        stk.push(equations[i][0]);
                        vis.emplace(equations[i][0],vis[cur]/values[i]);
                    }
                }
            }
        }
        return ans;
    }
};
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> p(n);
        iota(p.begin(),p.end(),0);
        sort(edgeList.begin(),edgeList.end(),[](auto& a,auto& b){return a[2]<b[2];});
        function<int(int)> find = [&](int x)->int{
            if(p[x]!=x)p[x]=find(p[x]);
            return p[x];
        };
        int m = queries.size();
        vector<bool> ans(m);
        vector<int> qid(m);
        iota(qid.begin(),qid.end(),0);
        sort(qid.begin(),qid.end(),[&](int i,int j){return queries[i][2]<queries[j][2];});
        int j = 0;
        for(int i:qid){
            int limit = queries[i][2];
            for(;j<edgeList.size()&&edgeList[j][2]<limit;++j){
                int ra = find(edgeList[j][0]);
                int rb = find(edgeList[j][1]);
                p[ra] = rb;
            }
            ans[i] = find(queries[i][0])==find(queries[i][1]);
        }
        return ans;
    }
};
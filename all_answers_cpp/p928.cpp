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
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> s(n,1);
        vector<int> p(n);
        iota(p.begin(),p.end(),0);
        function<int(int)> find = [&](int x)->int{
            if(p[x]!=x)p[x] = find(p[x]);
            return p[x];
        };
        function<void(int,int)> merge = [&](int a,int b){
            int ra = find(a),rb = find(b);
            if(ra!=rb){
                s[ra]+=s[rb];
                p[rb] = ra;
            }
        };
        vector<char> is_initial(n,false);
        for(int i = 0;i<initial.size();++i){
            is_initial[initial[i]] = true;
        }
        for(int i = 0;i<n;++i){
            for(int j = i+1;j<n;++j){
                if(is_initial[i]||is_initial[j])continue;
                if(graph[i][j]==1)merge(i,j);
            }
        }
        vector<unordered_set<int>> count(n);
        for(int i = 0;i<initial.size();++i){
            for(int j = 0;j<n;++j){
                if(is_initial[j])continue;
                if(graph[initial[i]][j]==1)count[find(j)].emplace(initial[i]);
            }
        }
        int ans = 0;
        int saved = -1;
        for(int i = 0;i<initial.size();++i){
            int cur_ans = initial[i];
            int cur_saved = 0;
            unordered_set<int> vis;
            for(int j = 0;j<n;++j){
                if(is_initial[j])continue;
                if(graph[initial[i]][j]==1&&count[find(j)].size()==1&&vis.count(find(j))==0){
                    cur_saved+=s[find(j)];
                    vis.emplace(find(j));
                }
            }
            if(cur_saved>saved){
                ans = cur_ans;
                saved = cur_saved;
            }
            if(cur_saved==saved){
                ans = ans<=cur_ans?ans:cur_ans;
            }
        }
        return ans;
    }
};
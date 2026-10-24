#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(),n = forest[0].size();
        vector<pair<int,int>> tree;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(forest[i][j]>1){
                    tree.push_back({forest[i][j],i*n+j});
                }
            }
        }
        sort(tree.begin(),tree.end());
        vector<int> dist(n*m);
        vector<int> dir = {-1,0,1,0,-1};
        auto f = [&](int cur,int target){
            int x = abs(target/n-cur/n);
            int y = abs(target%n-cur%n);
            return x+y;
        };
        auto ASharp = [&](int from,int to){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
            fill(dist.begin(),dist.end(),INT_MAX);
            q.push({f(from,to),from});
            dist[from]=0;
            int new_i;
            while(q.size()){
                auto[_,index] = q.top();
                q.pop();
                if(index==to) return dist[index];
                for(int k = 0;k<4;++k){
                    if(index%n+dir[k+1]<0||index%n+dir[k+1]>=n){
                        continue;
                    }
                    new_i = index+dir[k]*n+dir[k+1];
                    if(0<=new_i&&new_i<n*m&&forest[new_i/n][new_i%n]&&dist[new_i]>dist[index]+1){
                        dist[new_i]=dist[index]+1;
                        q.push({f(new_i,to)+dist[new_i],new_i});
                    }
                }
            }
            return -1;
        };
        int ans = 0;
        int cur;
        int start = 0;
        int end;
        for(auto t:tree){
            end = t.second;
            cur = ASharp(start,end);
            if(cur==-1){
                return -1;
            }
            ans+=cur;
            start = end;
        }
        return ans;
    }
};
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
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int ans = 0;
        vector<int> bucket(k);
        sort(jobs.begin(),jobs.end(),greater<int>());
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i = 0;i<n;++i){
            if(i<k){
                q.push(jobs[i]);
            }else{
                int t = jobs[i]+q.top();
                q.pop();
                q.push(t);
            }
        }
        while(q.size()){
            ans = max(ans,q.top());
            q.pop();
        }
        function<void(int)> DFS = [&](int i){
            if(i==n){
                ans = min(ans,*max_element(bucket.begin(),bucket.end()));
                return;
            }
            for(int j = 0;j<k;++j){
                if(bucket[j]+jobs[i]>=ans)continue;
                bucket[j]+=jobs[i];
                DFS(i+1);
                bucket[j]-=jobs[i];
                if(!bucket[j])break;
            }
        };
        DFS(0);
        return ans;
    }
};
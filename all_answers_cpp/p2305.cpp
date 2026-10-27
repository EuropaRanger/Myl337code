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
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> chil(k);
        sort(cookies.begin(),cookies.end(),greater<int>());
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i = 0;i<n;++i){
            if(i<k){
                q.push(cookies[i]);
            }else{
                int t = q.top()+cookies[i];
                q.pop();
                q.push(t);
            }
        }
        int ans = 0;
        while(q.size()){
            ans = max(ans,q.top());
            q.pop();
        }
        function<void(int)> DFS = [&](int i){
            if(i==n){
                ans = min(ans,*max_element(chil.begin(),chil.end()));
                return;
            }
            for(int j = 0;j<k;++j){
                if(chil[j]+cookies[i]>=ans)continue;
                chil[j]+=cookies[i];
                DFS(i+1);
                chil[j]-=cookies[i];
                if(!chil[j])return;
            }
        };
        DFS(0);
        return ans;
    }
};
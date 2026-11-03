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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> a(n);
        for(int i = 0;i<n;++i){
            a[i] = {scores[i],ages[i]};
        }
        sort(a.begin(),a.end());
        vector<int> dp(n);
        for(int i = 0;i<n;++i){
            for(int j = 0;j<i;++j){
                if(a[i].second>=a[j].second){
                    dp[i] = max(dp[j],dp[i]);
                }
            }
            dp[i]+=a[i].first;
        }
        return * max_element(dp.begin(),dp.end());
    }
};
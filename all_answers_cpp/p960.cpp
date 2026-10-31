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
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size(),m = strs.size();
        if(n==1)return 0;
        vector<int> f(n, 1);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                bool flag = true;
                for(int k = 0;k<m;++k){
                    flag = flag&&(strs[k][j]<=strs[k][i]);
                    if(!flag)break;
                }
                if(flag)f[i] = max(f[i],f[j]+1);
            }
            ans = max(ans,f[i]);
        }
        return n-ans;
    }
};
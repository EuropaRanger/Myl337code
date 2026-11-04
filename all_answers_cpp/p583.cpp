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
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<int> cur(m+1);
        vector<int> next(m+1);
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=m;++j){
                if(word1[i-1]==word2[j-1]){
                    next[j] = cur[j-1]+1;
                }else{
                    next[j] = max(next[j-1],cur[j]);
                }
            }
            swap(next,cur);
        }
        return m+n-2*cur[m];
    }
};
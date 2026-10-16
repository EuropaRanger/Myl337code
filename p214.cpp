#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s + "#" + string(s.rbegin(), s.rend());
        int n = t.size();
        vector<int> next(n);
        int longestPref = 0;
        next[0] = 0;
        for(int i = 1;i<n;++i){ 
            while(t[longestPref]!=t[i]&&longestPref){
                longestPref=next[longestPref-1];
            }
            if(t[longestPref]==t[i]){
                ++longestPref;
            }
            next[i] = longestPref;
        }
        return string(s.rbegin(), s.rbegin() + s.size() - next[n - 1]) + s;
    }
};
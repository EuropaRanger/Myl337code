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
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string,int>str2idx;
        int n = words.size();
        for(int i = 0;i<n;++i){
            str2idx[words[i]]=i;
        }
        for(int i = 0;i<n;++i){
            for(int j = 0;j<=words[i].size();++j){
                string cur = words[i];
                string a = cur.substr(0,j);
                string b = cur.substr(j);

            if (isPalin(a)) {
                string rb = b; reverse(rb.begin(), rb.end());
                auto it = str2idx.find(rb);
                if (it != str2idx.end() && it->second != i)
                    res.push_back({it->second, i});
            }
            if (j != 0 && isPalin(b)) {
                string ra = a; reverse(ra.begin(), ra.end());
                auto it = str2idx.find(ra);
                if (it != str2idx.end() && it->second != i)
                    res.push_back({i, it->second});
            }
            }
        }
        return res;
    }

    bool isPalin(string& s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            --j;
            ++i;
        }
        return true;
    }
};
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int m = s.size();
        vector<int> us(m+1);
        iota(us.begin(),us.end(),0);
        function<int(int)> find = [&](int x)->int{
            if(us[x]!=x)us[x] = find(us[x]);
            return us[x];
        };
        for(int i = 0;i<pairs.size();++i){
            int ra = find(pairs[i][0]);
            int rb = find(pairs[i][1]);
            us[ra] = rb;
        }
        vector<vector<char>> d(m);
        for(int i = 0;i<m;++i){
            d[find(i)].push_back(s[i]);
        }
        for(auto& e:d){
            sort(e.rbegin(),e.rend());
        }
        for(int i = 0;i<m;++i){
            auto& e = d[find(i)];
            s[i] = e.back();
            e.pop_back();
        }
        return s;   
    }
};
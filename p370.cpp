#include <vector>
#include <string>
#include <functional>
#include <utility> 
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> d(length+1);
        for(int i = 0;i<updates.size();++i){
            d[updates[i][0]] += updates[i][2];
            d[updates[i][1]+1] -= updates[i][2];
        }
        for(int i = 1;i<length;++i){
            d[i] += d[i-1];
        }
        d.pop_back();
        return d;
    }
};
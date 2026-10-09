#include <vector>
#include <string>
#include <functional>
#include <utility> 
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int hashSet[128]{};
        int cur = 0;
        int res = 0;
        while(cur<s.size()){
            if(!hashSet[s[cur]]){
                ++hashSet[s[cur]];
                ++cur;
            }else{
                res = cur-start>res?cur-start:res;
                while(s[start]!=s[cur]){
                    --hashSet[s[start]];
                    ++start;
                }
                ++start;
                ++cur;
            }
        }
        res = cur-start>res?cur-start:res;
        return res;
    }
};
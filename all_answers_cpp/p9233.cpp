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
    int countDigitOne(int n) {
        int cur_d = 1;
        int count = 0;
        int s = 0;
        while(cur_d<n){
            s = n/(cur_d<<1);
            count+=s*cur_d;
            count+=max(n-s*(cur_d<<1)-(cur_d-1),0);
            cur_d=cur_d<<1;
        }
        return count;
    }
};
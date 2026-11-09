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
    int countNumbersWithUniqueDigits(int n) {
        int d = 9;
        int ans = 1;
        for(int i = 0;i<n;++i){
            ans*=d;
            if(i==0)continue;
            --d;
        }
        if(n>0)ans+=countNumbersWithUniqueDigits(n-1);
        return ans;
    }
};
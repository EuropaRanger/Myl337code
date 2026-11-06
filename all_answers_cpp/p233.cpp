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
        long long count = 0;
        long long i = 1;  // 当前考察的位：1, 10, 100, ...

        while (i <= n) {
            long long high = n / (i * 10);
            long long cur  = (n / i) % 10;
            long long low  = n % i;
            if (cur == 0) {
                count += high * i;
            } else if (cur == 1) {
                count += high * i + low + 1;
            } else {
                count += (high + 1) * i;
            }

            i *= 10;
        }
        return count;
    }
};
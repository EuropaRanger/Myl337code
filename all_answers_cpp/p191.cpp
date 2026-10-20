#include <vector>
#include <string>
#include <functional>
#include <utility> 
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while(n>0){
            if(n%2)++res;
            n=n>>1;
        }
        return res;
    }
};
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
    int findIntegers(int n) {
        int i = 1;
        int d = 1;
        while(i<=n){
            i = i<<1;
            ++d;
        }
        i = i>>1;
        --d;
        function<int(int,int)> recur = [&](int dig,int one)->int{
            if(dig<=0)return 1;
            int new_d = dig-1;
            one = one>>1;
            while((n&one)==0 && new_d>0){
                one = one>>1;
                --new_d;
            }
            if(new_d==dig-1)return fib(dig)+fib(new_d);
            return fib(dig)+recur(new_d,one);
        };
        return recur(d,i);
    }

    int fib(int n){
        if(n<=1)return 1;
        int a = 1;
        int b = 1;
        int c = 0;
        for(int i = 2;i<=n;++i){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};
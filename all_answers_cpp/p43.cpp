#include <vector>
#include <string>
#include <functional>
#include <utility> 
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 =="0"||num2=="0"){
            return "0";
        }
        int m = num1.size();
        int n = num2.size();
        vector<int> product(m+n);
        for(int i = m-1;i>=0;--i){
            for(int j = n-1;j>=0;--j){
                product[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i = m+n-1;i;--i){
            product[i-1] += product[i]/10;
            product[i] %= 10;
        }
        string ans = "";
        for(int i = product[0]?0:1;i<m+n;++i){
            ans+='0'+product[i];
        }
        return ans;
    }
};
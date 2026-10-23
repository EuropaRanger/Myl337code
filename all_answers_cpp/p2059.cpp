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
    int minimumOperations(vector<int>& nums, int start, int goal) {
        auto check_range = [&](int x){return 0<=x&&x<=1000;};
        int n = nums.size();
        char visited[1001];
        queue<int> q;
        q.push(start);
        visited[start]='1';
        for(int step=1;q.size();++step){
            for(int edge=q.size();edge;--edge){
                int a = q.front();
                q.pop();
                for(int i:nums){
                    int x = a+i;
                    if(x==goal){
                        return step;
                    }
                    if(check_range(x)&&visited[x]!='1'){
                        visited[x]='1';
                        q.push(x);
                    }
                    x = a-i;
                    if(x==goal){
                        return step;
                    }
                    if(check_range(x)&&visited[x]!='1'){
                        visited[x]='1';
                        q.push(x);
                    }
                    x = a^i;
                    if(x==goal){
                        return step;
                    }
                    if(check_range(x)&&visited[x]!='1'){
                        visited[x]='1';
                        q.push(x);
                    }
                }
            }
        }
        return -1;
    }
};
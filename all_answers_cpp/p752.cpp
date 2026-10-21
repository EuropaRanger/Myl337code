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
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> set;
        for(string s:deadends){
            set.emplace(s);
        }
        if(set.find("0000")!=set.end()){
            return -1;
        }
        if(target=="0000"){
            return 0;
        }
        unordered_set<string> visted;
        queue<string> q;
        visted.emplace("0000");
        q.push("0000");
        string x;
        for(int step=1;q.size();++step){
            for(int edge = q.size();edge;--edge){
                auto a = q.front();
                q.pop();
                for(int j = 0;j<4;++j){
                    x = a;
                    x[j] = (x[j]-'0'+1)%10+'0';
                    if(x==target){
                        return step;
                    }
                    if(set.find(x)==set.end()&&visted.find(x)==visted.end()){
                        visted.emplace(x);
                        q.push(x);
                    }
                    x = a;
                    x[j] = (x[j]-'0'+9)%10+'0';
                    if(x==target){
                        return step;
                    }
                    if(set.find(x)==set.end()&&visted.find(x)==visted.end()){
                        visted.emplace(x);
                        q.push(x);
                    }
                }
            }
        }
        return -1;
    }
};
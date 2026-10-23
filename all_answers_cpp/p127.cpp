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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.size();
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        string x;
        for(int step=2;q.size();++step){
            for(int edge = q.size();edge;--edge){
                string a = q.front();
                q.pop();
                x = a;
                for(int ic = 0;ic<len;++ic){
                    for(char c = 'a';c<='z';++c){
                        x[ic]=c;
                        if(words.count(x)){
                            if(x==endWord){
                                return step;
                            }
                            q.push(x);
                            words.erase(x);
                        }
                    }
                    x[ic] = a[ic];
                }
            }
        }
        return 0;
    }
};
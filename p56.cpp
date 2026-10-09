#include <vector>
#include <string>
#include <functional>
#include <utility> 
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        function<void(int,int)> quicksort = [&](int l,int r){
            if(l>=r){
                return;
            }
            int x = intervals[(r+l)>>1][0];
            int i = l-1,j = r+1;
            while(i<j){
                while(intervals[++i][0]<x){}
                while(intervals[--j][0]>x){}
                if(i<j){
                    swap(intervals[i],intervals[j]);
                }
            }
            quicksort(l,j);
            quicksort(j+1,r);
        };
        quicksort(0,intervals.size()-1);
        vector<vector<int>> res = {intervals[0]};
        int last;
        for(int i = 1;i<intervals.size();++i){
            last = res.size()-1;
            if(intervals[i][0]<=res[last][1]){
                res[last][1] = intervals[i][1]>res[last][1]?intervals[i][1]:res[last][1];
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
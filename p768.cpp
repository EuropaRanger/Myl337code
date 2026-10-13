#include <vector>
#include <string>
#include <functional>
#include <utility> 
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int num = -1;
        int index = -1;
        vector<int> leftMax(n);
        vector<int> rightMin(n);
        for(int i = 0;i<n;++i){
            if(arr[i]>num){
                num = arr[i];
                index = i;
            }
            leftMax[i] = index;
        }
        num = 100000000+1;
        index = -1;
        for(int i = n-1;i>=0;--i){
            if(arr[i]<num){
                num = arr[i];
                index = i;
            }
            rightMin[i] = index;
        }
        int ans = 1;
        for(int i = 0;i<n-1;++i){
            if(arr[rightMin[i+1]]>=arr[leftMax[i]]){
                ans++;
            }
        }
        return ans;
    }
};
#include <vector>
#include <string>
#include <functional>
#include <utility> 
using namespace std;

class NumArray {
private:
    int* sum;
public:
    NumArray(vector<int>& nums) {
        sum = new int[nums.size()];
        sum[0] = nums[0];
        for(int i = 1;i<nums.size();++i){
            sum[i] = nums[i]+sum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return left?sum[right]-sum[left-1]:sum[right];
    }
};
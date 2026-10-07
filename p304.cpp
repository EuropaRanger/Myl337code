#include <vector>
#include <string>
#include <functional>
#include <utility> 
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        sum.resize(matrix.size(), vector<int>(matrix[0].size()));
        sum[0][0] = matrix[0][0];
        for(int j = 1;j<matrix[0].size();++j){
            sum[0][j] = sum[0][j-1]+matrix[0][j];
        }
        for(int i = 1;i<matrix.size();++i){
            sum[i][0] = sum[i-1][0]+matrix[i][0];
            for(int j = 1;j<matrix[0].size();++j){
                sum[i][j] = sum[i][j-1]+sum[i-1][j]+matrix[i][j]-sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = sum[row2][col2];
        int b = col1?sum[row2][col1-1]:0;
        int c = row1?sum[row1-1][col2]:0;
        int d = col1&&row1?sum[row1-1][col1-1]:0;
        return a+d-b-c;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool existedRowZero = false, existedColZero = false;
        int rowSize = matrix.size(), colSize = matrix.at(0).size();
        for(int j = 0; j < colSize; ++j)
            if(matrix[0][j] == 0) {
                existedRowZero = true;
                break;
            }
        for(int i = 0; i < rowSize; ++i)
            if(matrix[i][0] == 0) {
                existedColZero = true;
                break;
            }
        for(int i = 1; i < rowSize; ++i) {
            for(int j = 1; j < colSize; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int j = 1; j < colSize; ++j) {    
            if(matrix[0][j] == 0) {
                for(int k = 0; k < rowSize; ++k) {
                    matrix[k][j] = 0;
                }
            }
        }

        for(int i = 1; i < rowSize; ++i) {
            if(matrix[i][0] == 0) {
                for(int k = 0; k < colSize; ++k) {
                    matrix[i][k] = 0;
                }
            }
        }

        for(int j = 0; j < colSize; ++j)
            if(existedRowZero)
                matrix[0][j] = 0;
        for(int i = 0; i < rowSize; ++i)
            if(existedColZero)
                matrix[i][0] = 0;
    }
};
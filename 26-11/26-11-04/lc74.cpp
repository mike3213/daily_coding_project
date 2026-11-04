#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.at(0).size();
        int left = 1, right = m * n;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            int x = mid / n, y = mid % n;
            if(y != 0)
                x += 1;
            else {
                y = n;
            }
            if(target == matrix[x- 1][y - 1])
                return true;
            else if(target < matrix[x- 1][y - 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};

int main(void) {

    return 0;
}
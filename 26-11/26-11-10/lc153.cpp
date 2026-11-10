#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right - 1]) {
                left = mid + 1;
            } else if(nums[mid] < nums[right - 1]) {
                right = mid + 1;
            } else {
                if(nums[left] > nums[mid])
                    left = mid;
                break;
            }
        }
        return nums[left];
    }
};


int main(void) {

    return 0;
}
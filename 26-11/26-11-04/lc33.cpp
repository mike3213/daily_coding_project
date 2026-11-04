#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid])
                return mid;

            if(nums[left] <= nums[mid]) {
                if(target >= nums[left] && target < nums[mid]) {
                    right = mid;
                } else
                    left = mid + 1;
            } else {
                if(target > nums[mid] && target <= nums[right - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return -1;
    }
};

int main(void) {

    return 0;
}
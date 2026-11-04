#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(target <= nums[mid])
                right = mid;
            else
                left = mid + 1;
        }
        int first = left;
        
        left = 0, right = nums.size();
        while(left <right) {
            int mid = left + (right - left) / 2;
            if(target >= nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        int second = left;

        if(first >= nums.size() || nums[first] != target)
            return vector<int>({-1, -1});
        else
            return vector<int>({first, second});
    }
};

int main(void) {


    return 0;
}
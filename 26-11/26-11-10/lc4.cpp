#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int total = nums1.size() + nums2.size();
            if(total % 2 != 0)
                return getKth(nums1, nums2, total / 2 + 1);
            else
                return getKth(nums1, nums2, total / 2) + getKth(nums1, nums2, total / 2 + 1) / 2.0;
    }
private:
    int getKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size(), size2 = nums2.size();
        int i = 0, j = 0;
        while(true) {
            if(i == size1)
                return nums2[j + k - 1];
            if(j == size2)
                return nums1[i + k - 1];
            if(k == 1)
                return min(nums1[i], nums2[j]);
            int cnt1 = min(k / 2, size1 - 1 - i + 1);
            int cnt2 = min(k / 2, size2 - 1 - j + 1);
            if(nums1[i + cnt1 - 1] < nums2[j + cnt2 - 1]) {
                i += cnt1;
                k -= cnt1;
            } else {
                j += cnt2;
                k -= cnt2;
            }
        }
    }
};


int main(void) {


    return 0;
}
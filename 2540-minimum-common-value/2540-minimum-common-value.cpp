class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // fix nums1, find in nums2 with binary search
        // TC: O(nlogm), n is nums1 size, m is nums2 size
        // SC: O(1)
        for (auto const& num1 : nums1) {
            int low = 0;
            int high = nums2.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums2[mid] == num1) {
                    return num1;
                } else if (nums2[mid] > num1) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        // binary search
        // TC: O(logn)
        // SC: O(1)

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[right]) {
                if (mid == 0 || nums[mid - 1] > nums[mid]) {
                    return nums[mid];
                } else {
                    right = mid - 1;
                }
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
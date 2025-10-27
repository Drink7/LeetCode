class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // upper bound and lower bound
        // TC: O(logn * 2)
        // SC: O(1)
        int left = 0;
        int right = nums.size();

        //first
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (left >= nums.size() || nums[left] != target) return {-1, -1};
        int first = left;

        left = 0;
        right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (left - 1 < 0 || nums[left - 1] != target) return {-1, -1};
        return {first, left - 1};
    }
};
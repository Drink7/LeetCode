class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // lower bound -> first element >= target
        // last pos -> (the first element >= target + 1) - 1
        // TC: O(logn)
        // SC: O(n)
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        } else {
            int end = lower_bound(nums, target + 1) - 1;
            return {start, end};
        }
    }

    int lower_bound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
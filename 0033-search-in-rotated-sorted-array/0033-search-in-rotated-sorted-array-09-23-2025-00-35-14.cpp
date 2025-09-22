class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find which part is sorted
        // TC: O(logn)
        // SC: O(1)
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;

            if (nums[mid] <= nums[high]) {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            } else {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (low < nums.size() && nums[low] == target) {
            return low;
        }
        return -1;
    }
};
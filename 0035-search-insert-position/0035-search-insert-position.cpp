class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Find the first larger or equal to the target element index
        // TC: O(logn)
        // SC: O(1)
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                if (mid == 0 || nums[mid - 1] < target) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else {
                low = mid + 1;
            }
        }
        return nums.size();
    }
};
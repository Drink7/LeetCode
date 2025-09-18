class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binary search -> sorted, find one target
        // TC: O(logn)
        // SC: O(1)
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
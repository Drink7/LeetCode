class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // find maximum
        // TC: O(logn)
        // SC: O(1)
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
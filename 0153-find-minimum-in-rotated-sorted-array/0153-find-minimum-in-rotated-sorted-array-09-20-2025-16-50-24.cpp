class Solution {
public:
    int findMin(vector<int>& nums) {
        // 4 5 6 7 0 1 2
        // TC: O(logn)
        // SC: O(1)
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= nums[high]) {
                if (mid == 0 || nums[mid - 1] > nums[mid]) {
                    return nums[mid];
                } else {
                    high = mid - 1;
                }
            } else {
                // mid >= high
                low = mid + 1;
            }
        }
        return -1; // impossible
    }
};
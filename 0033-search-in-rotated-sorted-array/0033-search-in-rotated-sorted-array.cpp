class Solution {
public:
    int search(vector<int>& nums, int target) {
        // logn -> binary search
        // TC: O(logn)
        // SC: O(1)
        //  target = 4
        // 1 2 3 4 5, mid < target
        // 5 1 2 3 4, mid < target
        // 4 5 1 2 3, mid < target
        // 3 4 5 1 2, mid > target
        // 2 3 4 5 1
        // mid < target
        // -> mid > low, find right
        // -> else, find left
        // mid > target
        // -> mid <= high, find right
        // -> else, find left

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            
            // check if sorted in the later half
            // right half sorted
            if (nums[mid] < nums[high]) {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                // left half sorted
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 0, 1, 2, 3
        // 3, 0, 1, 2
        // 2, 3, 0, 1
        // 1, 2, 3, 0
        // if left < mid, front sorted
        // left <= target < mid, find left, or find right
        // else back sorted
        // mid < target <= right, find right, or find left
        // TC: O(logn)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else {
                if (nums[left] <= nums[mid]) {
                    // left part sorted
                    if (nums[left] <= target && target < nums[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    // right part sorted
                    if (nums[mid] < target && target <= nums[right]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
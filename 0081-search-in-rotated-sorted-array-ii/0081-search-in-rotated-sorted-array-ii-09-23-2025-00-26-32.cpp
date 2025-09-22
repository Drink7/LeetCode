class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Similar to LC. 33
        // Handle duplicate
        // TC: O(logn)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
                // The condition arr[mid] == arr[l] == arr[r] can be checked before the original logic
                // if so then move left and right both towards the middle by 1 and repeat.
                left++;
                right--;
            } else if (nums[mid] > nums[right]) {
                // Array must be rotated
                // check left part
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // Array might be rotated
                // check right part
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
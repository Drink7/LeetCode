class Solution {
public:
    int findMin(vector<int>& nums) {
        // TC: O(log n)
        // SC: O(1)
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[right]) {
                return nums[left];
            } else {
                // must be rotated
                if (mid > 0 && nums[mid - 1] > nums[mid]) {
                    return nums[mid];
                } else {
                    if (nums[left] > nums[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
        return -1; // impossible
    }
};
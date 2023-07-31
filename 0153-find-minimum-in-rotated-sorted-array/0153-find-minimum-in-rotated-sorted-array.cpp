class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        // O(n) solution
        // TC: O(n)
        // SC: O(1)
        if (nums[0] <= nums.back()) {
            return nums[0];
        }

        for (auto const& num : nums) {
            if (num < nums[0]) {
                return num;
            }
        }
        return -1;
        */

        // num[mid] > num[right]
        // smaller part is on the right
        // num[mid] < num[right]
        // smaller part is on the left
        // TC: O(logn)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[(mid + 1) % nums.size()] && nums[mid] < nums[(mid + nums.size() - 1) % nums.size()]) {
                return nums[mid];
            } else if (nums[mid] > nums[right]) {
               left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};
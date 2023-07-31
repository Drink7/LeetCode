class Solution {
public:
    int findMin(vector<int>& nums) {
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

        /*
        // TC: O(logn)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (left ==) {
                right = mid - 1;
            } else {
               
            }
        }
        return nums[left];
        */
    }
};
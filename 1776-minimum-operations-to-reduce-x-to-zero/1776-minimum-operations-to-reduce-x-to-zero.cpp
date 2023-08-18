class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Reverse thinking
        // Find the longest subarray which sum value is sum(nums) - X
        // TC: O(n)
        // SC: O(1)
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        int target = sum - x;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int curSum = 0;
        int maxLen = -1;
        while (right < n) {
            curSum += nums[right];
            while (left <= right && curSum > target) {
                curSum -= nums[left];
                left++;
            }
            if (curSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }

        if (maxLen == -1) {
            return -1;
        } else {
            return n - maxLen;
        }
    }
};
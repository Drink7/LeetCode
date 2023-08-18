class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Reverse thinking
        // Find the longest subarray which sum value is sum(nums) - X
        // TC: O(n)
        // SC: O(1)
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int remain = totalSum - x;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int longestResult = -1;
        while (right < n) {
            sum += nums[right];
            while (left <= right && sum > remain) {
                sum -= nums[left];
                left++;
            }
            if (sum == remain) {
                longestResult = max(longestResult, right - left + 1);
            }
            right++;
        }

        if (longestResult == -1) {
            return -1;
        } else {
            return n - longestResult;
        }
    }
};
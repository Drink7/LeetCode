class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // -2, 1, -3, 4, -1, 2, 1, -5, 4
        // -2, -1, -4, 0, -1, 1, 2, -3, 1
        // kandane dp
        // if previous sum < current num
        // start from current num
        // dp[i]: prev i number, max sum
        // dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
        // or keep adding
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        int result = INT_MIN;
        vector<int> dp(n + 1, 0);
        dp[0] = -100000;
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            result = max(result, dp[i]);
        }
        return result;
    }
};
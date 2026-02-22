class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algo
        // dp[i] = max(dp[i - 1], 0) + nums[i - 1])
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n + 1, -10001);
        int ans = nums[0];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i - 1], 0) + nums[i - 1];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
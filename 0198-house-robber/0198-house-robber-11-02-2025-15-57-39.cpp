class Solution {
public:
    int rob(vector<int>& nums) {
        // steal cur
        // dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1])
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[n];
    }
};
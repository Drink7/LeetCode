class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        // ith means the max value berfore ith nums
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n == 1) {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
        */
        // state dp
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        if (n == 1) {
            return nums[0];
        }

        dp[0][0] = nums[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][1] + nums[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
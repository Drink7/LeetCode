class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        // sum is 0 ~ 1000
        int offset = 1000;
        vector<vector<int>> dp(n + 1, vector<int>(2 * offset + 1, 0));
        dp[0][offset] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = -1000; j <= 1000; j++) {
                int plus = j + nums[i - 1];
                int minus = j - nums[i - 1];

                if (plus >= -offset && plus <= offset) {
                    dp[i][j + offset] += dp[i - 1][plus + offset];
                }
                if (minus >= -offset && minus <= offset) {
                    dp[i][j + offset] += dp[i - 1][minus + offset];
                }
            }
        }
        return dp[n][target + offset];
    }
};
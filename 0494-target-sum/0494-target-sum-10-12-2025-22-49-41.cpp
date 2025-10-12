class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (auto const& num : nums) {
            sum += num;
        }

        if (target > sum || target < -sum) {
            return 0;
        }

        int offset = sum;
        vector<vector<int>> dp(n + 1, vector<int>(2 * offset + 5, 0));
        dp[0][offset] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = -offset; j <= offset; j++) {
                int plus = j + nums[i - 1];
                int minus = j - nums[i - 1];

                if (minus >= -offset && minus <= offset) {
                    dp[i][j + offset] += dp[i - 1][minus + offset];
                }
                if (plus >= -offset && plus <= offset) {
                    dp[i][j + offset] += dp[i - 1][plus + offset];
                }
                
            }
        }
        return dp[n][target + offset];
    }
};
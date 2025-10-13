class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 2D DP
        // only even might be partitioned
        // TC: O(n * sum(nums)), n is nums size
        // SC: (n)
        int sum = 0;
        for (auto const& num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int n = nums.size();
        int halfSum = sum / 2;
        /*
        vector<vector<bool>> dp(n + 1, vector<bool>(halfSum + 1, false));
        dp[0][0] = true;

        // dp[i][j] means previous i numbers can sum to j?
        // nums[i - 1] not choose, dp[i][j] = dp[i - 1][j]
        // if j >= nums[i], nums[i - 1] choose, dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i]]

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= halfSum; j++) {
                // nums[i - 1] not choose
                dp[i][j] = dp[i - 1][j];

                // if j >= nums[i], nums[i - 1] choose
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][halfSum];
        */
        vector<bool> dp(halfSum + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = halfSum; j >= nums[i - 1]; j--) {
                if (dp[j -  nums[i - 1]]) {
                    dp[j] = true;
                }
            }
        }
        return dp[halfSum];
    }
};
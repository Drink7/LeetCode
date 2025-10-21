class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo;
        int n = nums.size();
        memo.resize(nums.size(), -1);
        return dfs(nums, memo, n - 1);
    }

    int dfs(vector<int>& nums, vector<int>& memo, int i) {
        if (i < 0) {
            return 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = max(dfs(nums, memo, i - 1), dfs(nums, memo, i - 2) + nums[i]);
        return memo[i];
    }
        /*
        // state dp
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        if (nums.size() == 1) {
            return nums[0];
        }

        dp[0][0] = nums[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][1] + nums[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
        /*
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[n];
        */
    //}
};
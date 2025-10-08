class Solution {
public:
    int rob(vector<int>& nums) {
        // state dp
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        /*
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0]
        }
        */
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[n];
    }
};
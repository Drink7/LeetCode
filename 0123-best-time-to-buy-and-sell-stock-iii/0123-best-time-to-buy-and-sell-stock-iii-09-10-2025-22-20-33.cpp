class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // follow guan concept
        // TC: O(n)
        // SC: O(n)
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        // dp[i][0] ith day hold 1
        // dp[i][1] ith day sold 1
        // dp[i][2] ith day hold 2
        // dp[i][3] ith day sold 2
        dp[0][0] = INT_MIN;
        dp[0][1] = 0;
        dp[0][2] = INT_MIN;
        dp[0][3] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(0 - prices[i - 1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i - 1], dp[i - 1][1]);
            dp[i][2] = max(dp[i - 1][1] - prices[i - 1], dp[i - 1][2]);
            dp[i][3] = max(dp[i - 1][2] + prices[i - 1], dp[i - 1][3]);
        }
        return max(dp[n][1], dp[n][3]);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // hold, sell, cooldown
        // hold -> ith hold is i - 1 hold and i - 1 cooldown - p
        // sell -> ith sell is i - 1 hold + p and i - 1 sole
        // cool down -> ith cool down is i - 1 sold and i - 1 cooldown
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][0] = INT_MIN;
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[n][1], dp[n][2]);
    }
};
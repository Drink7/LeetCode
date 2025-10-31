class Solution {
public:
    int maxProfit(vector<int>& prices) {
         // buy, sell, cooldown
         // i - 1 day buy sell cool
         // i day     buy sell cool
         // i-1 buy -> i buy sell
         // i - 1 sell -> sell, cool
         // i - 1 cool -> buy, cool
         // 2d dp, dp[i][j] means ith day with operation j, 0 for buy, 1 for sell, 2 for cool
         // check dp[n][1] and dp[n][2]
         // TC: O(n)
         // SC: O(n)
         int n = prices.size();
         vector<vector<int>> dp(n + 1, vector<int>(3, 0));

         dp[0][0] = -prices[0];
         dp[0][1] = -prices[0];
         dp[0][2] = 0;
         for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1]);
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
         }
         return max(dp[n][1], dp[n][2]);
    }
};
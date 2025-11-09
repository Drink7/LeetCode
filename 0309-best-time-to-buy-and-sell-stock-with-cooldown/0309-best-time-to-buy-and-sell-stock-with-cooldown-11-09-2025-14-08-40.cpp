class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // s1: can buy
        // s2: can sell
        // s3: cool down
        // i - 1: s1   s2   s3
        // i    : s1   s2   s3
        // s1->s1, s1->s2 (buy)
        // s2->s2, s2->s3 (sell)
        // s3->s1
        // TC: O(m * 3)
        // SC: O(m * 3)
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN; // impossible
        dp[0][2] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
            dp[i][2] = dp[i - 1][1] + prices[i - 1];
        }
        return max(dp[n][0], dp[n][2]);
    }
};
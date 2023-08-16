class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dynamic programming
        // calculate buy price to dp
        // use prices - dp and check the max profit
        // TC: O(n)
        // SC: O(n)
        vector<int> dp(prices.size(), 0);
        dp[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = min(dp[i - 1], prices[i]);
        }

        // calculate max profit
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - dp[i]);
        }
        return maxProfit;
    }
};
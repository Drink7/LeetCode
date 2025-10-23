class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // max profit
        // dp[i] -> the max profit we sell at i-th day
        // TC: O(n^2)
        // SC: O(n)
        int n = prices.size();
        int curSell = prices[0];
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (curSell > prices[i]) {
                // reset
                curSell = prices[i];
            }
            result = max(result, prices[i] - curSell);
        }
        return result;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // find a min value array
        // maintain a max profit value
        // TC: O(n)
        // SC: O(n)
        vector<int> minPrices(prices.size(), 0);
        int profit = 0;
        minPrices[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrices[i - 1]) {
                minPrices[i] = prices[i];
            } else {
                minPrices[i] = minPrices[i - 1];
            }
            profit = max(profit, prices[i] - minPrices[i]);
        }
        return profit;
    }
};
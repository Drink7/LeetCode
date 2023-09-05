class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        // find a min value array
        // maintain a max profit value
        // TC: O(n)
        // SC: O(n)
        vector<int> minPrices(prices.size(), 0);
        int profit = 0;
        minPrices[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            minPrices[i] = (prices[i] < minPrices[i - 1]) ? prices[i] : minPrices[i - 1];
            profit = max(profit, prices[i] - minPrices[i]);
        }
        return profit;
        */
        // two pointer
        // sliding windows
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = 0;
        int profit = 0;
        while (right < prices.size()) {
            int sellPrice = prices[right];
            if (sellPrice < prices[left]) {
                left = right;
            }
            profit = max(profit, sellPrice - prices[left]);
            right++;
        }
        return profit;
    }
};
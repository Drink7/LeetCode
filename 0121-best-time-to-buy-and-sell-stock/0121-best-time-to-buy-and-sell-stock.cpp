class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // one variable to keep min price
        // one variable to store max profit
        // TC: O(n)
        // SC: O(1)
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
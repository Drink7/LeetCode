class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp
        // buy_price / sell_price
        // if sell_price - buy_price < 0, buy_price = sell_price
        // calculate profit
        // TC: O(n)
        // SC: O(1)
        int buyPrice = prices[0];
        int sellPrice = prices[0];
        int maxProfit = sellPrice - buyPrice;
        for (int i = 1; i < prices.size(); i++) {
            sellPrice = prices[i];
            if (sellPrice - buyPrice < 0) {
                buyPrice = sellPrice;
            } else {
                maxProfit = max(maxProfit, sellPrice - buyPrice);
            }
        }
        return maxProfit;
    }
};
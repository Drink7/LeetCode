class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // sliding window
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = 0;
        int minPrice = prices[left];
        int profit = 0;
        while (right < prices.size()) {
            if (prices[right] < minPrice) {
                minPrice = prices[right];
            }
            profit = max(prices[right] - minPrice, profit);
            right++;
        }
        return profit;
    }
};
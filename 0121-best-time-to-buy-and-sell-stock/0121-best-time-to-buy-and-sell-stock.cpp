class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Sliding window
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = 0;
        int profit = 0;
        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            profit = max(profit, prices[right] - prices[left]);
            right++;
        }
        return profit;
    }
};
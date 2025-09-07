class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // sliding window move
        // right keep moving
        // left will change if a minimum value found
        // TC: O(n)
        // SC: O(1)
        int left = 0, right = 0;
        int n = prices.size();
        int profit = 0;
        while (right < n) {
            profit = max(profit, prices[right] - prices[left]);
            if (prices[right] < prices[left]) {
                left = right;
            }
            right++;
        }
        return profit;
    }
};
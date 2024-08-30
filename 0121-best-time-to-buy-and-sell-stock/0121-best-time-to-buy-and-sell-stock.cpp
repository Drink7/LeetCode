class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // sliding window
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = 0;
        int result = 0;
        int n = prices.size();
        while (right < n) {
            int profit = prices[right] - prices[left];
            if (profit > result) {
                result = profit;
            }
            right++;
            if (right < n && prices[right] < prices[left]) {
                left = right;
            }
        }
        return result;
    }
};
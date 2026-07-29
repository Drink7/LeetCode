class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // two pointer
        // slow track the sell day
        // fast track the buy day
        // memo the profit
        // TC: O(n)
        // SC: O(1)
        int profit = 0;
        int slow = 0, fast = 0;
        int n = prices.size();
        while (fast < n) {
            if (prices[fast] < prices[slow]) {
                slow = fast;
            }
            profit = max(profit, prices[fast] - prices[slow]);
            fast++;
        }
        return profit;

        // 7 1 5 3 6 4
        // slow = 0, fast = 0, profit = 0
        // slow = 0, fast = 1, profit = 0
        // slow = 1, fast = 1, profit = 0
        // slow = 1, fast = 2, profit = 4
        // slow = 1, fast = 3, profit = 4
        // slow = 1, fast = 4, profit = 5
        // slow = 1, fast = 5, profit = 5
        // profit = 5
    }
};
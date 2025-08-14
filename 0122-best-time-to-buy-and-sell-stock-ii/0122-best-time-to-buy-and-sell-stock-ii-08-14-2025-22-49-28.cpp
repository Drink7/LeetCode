class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Stock Problem without cooldown (LC. 399)
        // TC: O(n)
        // SC: O(n)
        // state1: able to buy
        // state1 -> state1 or state1 -> state2
        // state2 : able to sell
        // state2 -> state2 or state2 -> state1
        int n = prices.size();
        vector<int> state1(n, 0);
        vector<int> state2(n, 0);
        state2[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            state1[i] = max(state1[i - 1], state2[i - 1] + prices[i]);
            state2[i] = max(state2[i - 1], state1[i - 1] - prices[i]);
        }
        return max(state1[n - 1], state2[n - 1]);
    }
};
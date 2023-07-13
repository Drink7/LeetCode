class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // state machine (cooldown / sell / buy)
        // buy means profit - price, sell means profit + price
        // state1: cooldown
        // state2: buy
        // state3 : sell
        // TC: O(n)
        // SC: O(n)
        int n = prices.size();
        vector<int> state1(n, 0);
        vector<int> state2(n, 0);
        vector<int> state3(n, 0);
        state1[0] = 0;
        state2[0] = -prices[0];
        state3[0] = 0;
        for (int i = 1; i < n; i++) {
            state1[i] = max(state1[i - 1], state3[i - 1]);
            state2[i] = max(state2[i - 1], state1[i - 1] - prices[i]);
            state3[i] = state2[i - 1] + prices[i];
        }
        return max(state1[n - 1], state3[n - 1]);
    }
};
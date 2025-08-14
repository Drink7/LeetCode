class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dynamic programming state machine
        // TC: O(n)
        // SC: O(n)
        int n = prices.size();
        vector<int> state0(n, 0), state1(n, 0);
        state1[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            state0[i] = max(state0[i - 1], state1[i - 1] + prices[i]);
            state1[i] = max(state1[i - 1], state0[i - 1] - prices[i]);
        }
        return state0[n - 1];
    }
};
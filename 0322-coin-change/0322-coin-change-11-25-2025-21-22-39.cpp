class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] means the fewest number that can make up to the amount
        // TC: O(n)
        // SC: O(n)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto const& coin : coins) {
            for (int i = 1; i <= amount; i++) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        } 
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // TC: O(m * n), m is coins count, n is amount number
        // SC: O(n)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            for (int j = 1; j <= amount; j++) {
                if (j - coin >= 0) {
                    dp[j] = min(dp[j - coin] + 1, dp[j]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
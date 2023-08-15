class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dynamic programming
        // TC: O(mn), m is coins count, n is amount number
        // SC: O(n)
        vector<int> dp(amount + 1, 10001);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                if (j - coins[i] >= 0) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return (dp[amount] == 10001) ? -1 : dp[amount];
    }
};
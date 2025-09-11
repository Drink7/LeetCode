class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = min(dp[i], dp[i - coins[j]] + 1)
        // TC: O(n)
        // SC: O(n)
        vector<long long> dp(amount + 1, 10001);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};
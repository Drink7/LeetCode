class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // outer will use amount + 1
        // inner will use coins
        // dp[i] means how many ways to form amount i
        vector<int> dp(amount + 1, 10001);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto const& coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];

        /*
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));
    
        // base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // not choose
                dp[i][j] = dp[i - 1][j];

                // choose
                if (j - coins[i - 1] >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }
        return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
        */
    }
};
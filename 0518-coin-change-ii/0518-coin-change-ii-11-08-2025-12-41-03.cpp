class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 2d-dp
        // dp[i][j] means use prev i coins, check the amount combinations
        // coins can use unlimited (combinations, not permutations)
        // outer for loop coins, inner for loop loop amount
        // if dp[i][j - wi] is valid, dp[i][j] combination += dp[i][j - wi]
        // TC: O(amount * coins.size())
        // SC: O(amount * coins.size())
        //   0 1 2 3 4 5
        // 0 1 0 0 0 0 0 
        // 1 1 1 1 1 1 1
        // 2 1 1 2 2 3 3
        // 5 1 1 2 2 3 4
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // one way to get no amount
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // not choose
                dp[i][j] = dp[i - 1][j];

                if (j >= coins[i - 1]) {
                    dp[i][j] = (unsigned long long) dp[i][j] + dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[n][amount];
    }
};
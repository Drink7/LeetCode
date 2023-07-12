class Solution {
public:
    bool divisorGame(int n) {
        // Alice win bob lose
        // Alice lose bob win
        // dynamic programming
        // TC: O(n^2)
        // SC: O(n)
        bool dp[n + 1];
        fill_n(dp, n + 1, false);
        for (int i = 2; i <= n; i++) {
            int root = sqrt(i);
            for (int j = root; j > 0; j--) {
                if (i % j == 0) {
                    dp[i] |= !dp[i - j];
                }
            }
        }
        return dp[n];
    }
};
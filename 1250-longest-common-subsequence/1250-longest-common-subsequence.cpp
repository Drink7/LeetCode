class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Similar to 82.
        // TC: O(m * n), m is text1 size, n is text2 size
        // SC: O(m * n)
        int m = text1.size();
        int n = text2.size();
        int dp[m + 1][n + 1];
        fill_n(*dp, (m + 1) * (n + 1), 0);

        // start calculate all path
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
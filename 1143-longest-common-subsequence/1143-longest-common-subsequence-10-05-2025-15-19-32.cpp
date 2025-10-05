class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // compare both string
        // if cur == goal
        // 1 + max(dp[i][j - 1], dp[i - 1][j])
        // and we will go through row[0] and col[0] first
        // if we not going to go through row[0], col[0] first, we can just init a m + 1, n + 1 matrix
        // TC: O(m * n)
        // SC: O(m * n)
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[m][n];
    }
};
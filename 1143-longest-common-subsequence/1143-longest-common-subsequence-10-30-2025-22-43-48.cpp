class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] means the common length of text1 with ith end and text2 with jth end
        // if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1]
        // else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
        // The dp[m][n] will be the ans
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
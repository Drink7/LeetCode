class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j] means matrix ith jth right down corner, the max square we can get
        // dp[i][j] = min({dp[i - 1][j], dp[i][j], dp[i][j - 1]}) + 1 if matrix[i - 1][j - 1] == 1
        // TC: O(m * n)
        // SC: O(m * n)
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLen = 0;

        // 0 1
        // 1 0

        // 1 1 1   1 1 1
        // 0 1 1   0 1 2
        // 0 1 1   0 1 2
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen * maxLen;
    }
};
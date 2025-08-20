class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // DP from dp[m - 1][n - 1] side to dp[0][0]
        // TC: O(m * n)
        // SC: O(m * n)
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // if zero, not need to check
                if (matrix[i][j] == '0') {
                    continue;
                }

                // if one, at least one
                dp[i][j] += 1;

                // check down, right, diag
                if (i + 1 < m && j + 1 < n) {
                    dp[i][j] += min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
                }
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};
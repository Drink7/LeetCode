class Solution {
public:
    int uniquePaths(int m, int n) {
        // 2d-dp
        // dp[i][j] means the way to [i][j], dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        // TC: O(m * n)
        // SC: O(m * n)
        // m = 3, n = 2
        // dp array
        // 1 1
        // 1 2
        // 1 3
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // init 2d dp
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int i = 0; i < m; i++) dp[i][0] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
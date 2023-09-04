class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // similar to unique path, but we mark the obstacle to 0 path
        // TC: O(m * n)
        // SC: O(m * n)

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // init
        // note the corner case
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 0) {
                if (i >= 1) {
                    if (dp[0][i - 1] == 1) {
                        dp[0][i] = 1;
                    }
                } else {
                    dp[0][i] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                if (i >= 1) {
                    if (dp[i - 1][0] == 1) {
                        dp[i][0] = 1;
                    }
                } else {
                    dp[i][0] = 1;
                }
            }
        }

        // start from (1, 1)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
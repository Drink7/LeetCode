class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // similar to unique paths
        // obstacle is 0
        // dp[i][j] = dp[i][j - 1] if nums[i][j - 1] not 1 + dp[i - 1][j] if nums[i - 1][j] not 1
        // if nums[i][j - 1] is 1, dp[i][j - 1] = 0
        // TC: O(m * n)
        // SC: O(m * n)
        // #1 calcualte grid row and col size
        // #2 initialize 2d dp array with row, col size
        // #3 initialize first row and first col, notice the obstacle, if obstacle, dp grid will be 0
        // #4 traverse all grid, calculate grid with formula
        // #5 dp[i][j] = dp[i][j - 1] if nums[i][j - 1] not 1 + dp[i - 1][j] if nums[i - 1][j] not 1
        // return dp[row][col]
        // 0 0 0
        // 0 1 0
        // 0 0 0
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            } else {
                break;
            }
        }

        for (int j = 0; j < cols; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};
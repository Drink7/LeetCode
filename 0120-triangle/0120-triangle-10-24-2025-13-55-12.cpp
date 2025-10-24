class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //     2
        //    3 4
        //   6 5 7
        //  4 1 8 3
        // dp[i][j] means the minimum path sum at j in ith layer
        // row i - 1: i - 1, i ,i + 1
        // row i    : i - 1, i, i + 1
        // dp[i][j] = nums[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j])
        // TC: O(n ^ 2)
        // SC: O(n ^ 2)
        vector<vector<int>> dp(triangle);
        int h = triangle.size();

        for (int i = 1; i < h; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) { // head
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                } else if (j == i) { // tail
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }

        int result = INT_MAX;
        // find min path sum, check last level
        for (int i = 0; i < triangle[h - 1].size(); i++) {
            result = min(result, dp[h - 1][i]);
        }
        return result;
    }
};
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
        int result = INT_MAX;
        for (int i = 1; i < h; i++) {
            int width = triangle[i].size();
            dp[i][0] = triangle[i][0] + dp[i - 1][0];
            for (int j = 1; j < i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
            }

            dp[i][width - 1] = triangle[i][width - 1] + dp[i - 1].back();
        }

        // find min path sum, check last level
        for (int i = 0; i < triangle[h - 1].size(); i++) {
            result = min(result, dp[h - 1][i]);
        }
        return result;
    }
};
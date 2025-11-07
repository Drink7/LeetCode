class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j] means if the matrix[i - 1][j - 1] is the right down corner
        // what is its maximum edge size
        // TC: O(m * n)
        // SC: O(1)
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxEdge = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '0') continue;

                dp[i][j] = 1;
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
                maxEdge = max(maxEdge, dp[i][j]);
            }
        }
        return maxEdge * maxEdge;
    }
};
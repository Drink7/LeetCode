class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // get maximal square if we use bottom/right to record maximal edge size
        // dp[i][j] means maximal edge size we can get
        // dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) if nums[i - 1][j - 1] is 1
        // 1 1
        // 1 2
        // 1 1 1
        // 1 2 2
        // 1 2 3
        // TC: O(m * n)
        // SC: O(m * n)
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxEdge = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    maxEdge = max(maxEdge, dp[i][j]);
                }
            }
        }
        return maxEdge * maxEdge;
    }
};
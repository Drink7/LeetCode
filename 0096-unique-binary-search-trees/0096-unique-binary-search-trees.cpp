class Solution {
public:
    int numTrees(int n) {
        // dynamic programming
        // TC: O(n^2)
        // SC: O(n)
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            // calculate from dp[1]
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
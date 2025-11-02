class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // ex: 3 stairs, we try to get stairs 4 result
        // dp[i] = dp[i - 2] + dp[i - 1]
        // return last two min
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[n];
    }
};
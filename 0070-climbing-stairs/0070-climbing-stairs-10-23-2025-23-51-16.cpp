class Solution {
public:
    int climbStairs(int n) {
        // 
        // max way -> dp or greedy
        // stairs i, stairs i - 1 (go 1 steps) / stairs i - 2 (go 2 steps)
        // staris i ways = stairs i - 1 ways + stairs i - 2 ways
        // i = 0 ? -> neg index
        // stairs 1 -> 1
        // stairs 0 -> 1
        // TC: O(n)
        // SC: O(n)

        vector<int> dp (n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
class Solution {
public:
    int climbStairs(int n) {
        // recursive
        // TC: O(n)
        // SC: O(n)
        dp.resize(45 + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        return climbingHelper(n);
    }

    int climbingHelper(int n) {
        if (dp[n] != 0) {
            return dp[n];
        }
        dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return dp[n];
    }
private:
    vector<int> dp;
};
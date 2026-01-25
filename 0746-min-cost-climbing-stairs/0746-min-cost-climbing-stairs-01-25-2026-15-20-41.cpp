class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // TC: O(n)
        // SC: O(n)
        int n = cost.size();
        dp.resize(n + 1, -1);
        dp[0] = 0;
        dp[1] = 0;
        return climbCost(cost, n);
    }

    int climbCost(vector<int>& cost, int n) {
        if (n == 0 || n == 1) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int result =  min(climbCost(cost, n - 2) + cost[n - 2], climbCost(cost, n - 1) + cost[n - 1]);
        dp[n] = result;
        return dp[n];
    }

private:
    vector<int> dp;
};
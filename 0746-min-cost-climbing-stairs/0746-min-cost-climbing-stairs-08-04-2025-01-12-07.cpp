class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // use the previous value to reach target -> DP
        // sum[0] = cost[0], sum[1] = cost[1]
        // sum[2] = min(sum[0], sum[1]) + cost[2]
        // result = min(sum[2], sum[1]);
        // TC: O(n)
        // SC: O(n)
        int n = cost.size();
        vector<int> sum(n, 0);
        sum[0] = cost[0];
        sum[1] = cost[1];
        for (int i = 2; i < n; i++) {
            sum[i] = min(sum[i - 1], sum[i - 2]) + cost[i];
        }
        return min(sum[n - 1], sum[n - 2]);
    }
};
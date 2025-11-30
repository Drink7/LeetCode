class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // maximum jumps -> go as minimum stesp as you can
        // dynamic programming just like LIS
        // count the jumps
        // TC: O(n^2)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((j == 0 || dp[j] > 0) && abs(nums[j] - nums[i]) <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1] == 0 ? -1 : dp[n - 1];
    }
};
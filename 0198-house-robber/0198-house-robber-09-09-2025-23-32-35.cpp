class Solution {
public:
    int rob(vector<int>& nums) {
        // TC: O(n)
        // SC: O(n)
        // dp[i] means the max amount when we run through ith
        if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};
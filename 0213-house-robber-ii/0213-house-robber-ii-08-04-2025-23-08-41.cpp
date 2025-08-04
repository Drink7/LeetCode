class Solution {
public:
    int rob(vector<int>& nums) {
        // 1 & n are adjencent
        // 1. Rob the first house
        // 2. Rob the second house
        // TC: O(n)
        // SC: O(n)
        if (nums.size() == 1) {
            return nums[0];
        }

        int n = nums.size();
        vector<int> dp(n, 0);
        // dp1, 1 to n - 1
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int robFirst = dp[n - 2];

        // dp2, 2 to n
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int robSecond = dp[n - 1];

        return max(robFirst, robSecond);
    }
};
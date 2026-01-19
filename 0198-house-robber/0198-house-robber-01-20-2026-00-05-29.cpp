class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] how can I get the most value with previous i numbers
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        // the first house -> nums[0]
        // the second house -> nums[1]
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane algo
        // dp[i] means the max sum if ith is the end
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n + 1, -10001);
        int maxVal = -10001;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};
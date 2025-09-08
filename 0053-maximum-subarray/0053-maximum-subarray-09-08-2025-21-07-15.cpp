class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 1D-DP
        // dp store index i as subarray tail, the subarray sum
        // we then choose maximum value
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int maxValue = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = (dp[i - 1] + nums[i] > nums[i]) ? dp[i - 1] + nums[i] : nums[i];
            maxValue = max(maxValue, dp[i]);
        }
        return maxValue;
    }
};
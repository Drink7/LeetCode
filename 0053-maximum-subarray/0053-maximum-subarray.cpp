class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 1D DP Array
        // check the last array value
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        int maxVal = nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = (dp[i - 1] + nums[i] > nums[i]) ? dp[i - 1] + nums[i] : nums[i];
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};
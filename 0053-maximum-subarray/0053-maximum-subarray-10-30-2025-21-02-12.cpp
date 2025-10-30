class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane algorithm
        // dp[i] means max sum with ith number in the end
        // if nums[i] + dp[i - 1] <= num[i], dp[i] = nums[i]
        // else dp[i] = nums[i] + dp[i - 1]
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = -100001;
        int result = dp[0];
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            result = max(result, dp[i]);
        }
        return result;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dynamic programming
        // TC: O(n^2)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n, 1);
        int result = dp[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
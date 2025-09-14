class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // TC: O(n^2)
        // SC: O(n)
        // find maxiumum of previous numbers
        // then add it as the incresaing subsequence
        int n = nums.size();
        int result = -10001;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            // nums is 0 ~ n - 1
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
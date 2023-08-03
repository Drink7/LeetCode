class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // DP
        // TC: O(n^2)
        // SC: O(n)
        int n = nums.size();
        int maxLength = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLength = max(maxLength, dp[i]);
                }
            }
        }
        return maxLength;
    }
};
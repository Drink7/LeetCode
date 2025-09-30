class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] means what is the LIS if nums[i] is the end
        // i: 0 - n
        // j: i - 1 - n
        // if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1)
        // TC: O(n^2)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxVal = dp[0];
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxVal = max(maxVal, dp[i]);
                }
            }
        }
        return maxVal;
    }
};
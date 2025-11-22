class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] means ith element be the end, the max increasing length
        // TC: O(n^2)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n, 1);
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
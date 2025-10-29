class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] means if nums[i] is the end, how ling the LIS can be?
        // 10 ,9, 2, 5
        // dp[0] = 100001
        // dp[1] will check dp[0], can not add one
        // and we will check from 1 to i - 1 when is the nums[i] be the end
        // TC: O(n^2)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxVal = 0;
        // traverse the nums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};
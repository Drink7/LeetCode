class Solution {
public:
    int rob(vector<int>& nums) {
        // 1d dp
        // check if nums[i] is robbed, how much we can get if we must rob nums[i] houses
        // then get the max val of the last element in dp array
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            if (i == 1) {
                dp[i] = max(dp[i - 1], nums[i]);
            } else {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
        }
        return dp.back();
    }
};
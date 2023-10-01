class Solution {
public:
    int rob(vector<int>& nums) {
        // 1d dp
        // compare current + dp[current - 2] and dp[current - 1]
        // go to nums[i] does not mean we need to rob the house
        // TC: O(n)
        // SC: O(n)
        if (nums.size() == 1) {
            return nums[0];
        }

        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
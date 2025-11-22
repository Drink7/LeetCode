class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // knapsack problem
        // TC: O(2^n)
        // SC: O(n)
        vector<unsigned> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto const& num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
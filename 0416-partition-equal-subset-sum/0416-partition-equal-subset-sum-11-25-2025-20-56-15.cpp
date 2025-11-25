class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // two subset -> must be even
        // 01 knacksack problem
        // find subsetnsum = halfSum
        // TC: O(n)
        // SC: O(n)
        int sum = 0;
        for (auto const& num : nums) {
            sum += num;
        }

        if (sum % 2== 1) {
            return false;
        }

        int halfSum = sum / 2;
        vector<bool> dp(halfSum + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = halfSum; j >= 0; j--) {
                if (j >= nums[i]) {
                    dp[j] = dp[j] | dp[j - nums[i]];
                }
            }
        }
        return dp[halfSum];
    }
};
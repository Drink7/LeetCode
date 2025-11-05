class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // odd -> false
        // subset sum -> 0/1 knacksack
        // TC: O(n * sum(nums))
        // SC: O(n)
        int sum = 0;
        for (auto const& num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) return false;
        int halfSum = sum / 2;
        vector<bool> dp(halfSum + 1, 0);
        dp[0] = true;
        for (auto const& num : nums) { // item weight
            for (int i = halfSum; i >= 1; i--) { // knackpack size
                if (i >= num) {
                    dp[i] = dp[i] || dp[i - num];
                }
            }
        }
        return dp[halfSum];
    }
};
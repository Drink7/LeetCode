class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // TC: O(n^2)
        // SC: O(n)
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }

        int halfSum = sum / 2;
        bool dp[halfSum + 1];
        fill_n(dp, halfSum + 1, false);
        dp[0] = true;
        for (auto const& num : nums) {
            for (int i = halfSum; i >= num; i--) { // essential to go from right to left
                if (dp[i - num]) {
                    dp[i] = true;
                }
            }
        }
        return dp[halfSum];
    }
};
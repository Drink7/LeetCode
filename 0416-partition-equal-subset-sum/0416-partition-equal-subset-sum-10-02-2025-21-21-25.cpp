class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // sum up
        // if sum is odd, must false
        int sum = 0;
        for (auto const& num : nums) {
            sum += num;
        }

        if (sum % 2) {
            return false;
        }

        int halfSum = sum / 2;
        vector<bool> dp(halfSum + 1, false);
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
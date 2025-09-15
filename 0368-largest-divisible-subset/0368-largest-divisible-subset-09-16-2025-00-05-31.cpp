class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Same logic as LIS, but sort first
        // TC: O(n^2)
        // SC: O(n^2)
        sort(nums.begin(), nums.end());
        int ansId = 0;
        int n = nums.size();
        vector<vector<int>> dp(n); // dp[i] means subset with nums[i] by the end
        for (int i = 0; i < n; i++) {
            dp[i] = {nums[i]};
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i].size() < dp[j].size() + 1) {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }
            }
            if (dp[i].size() > dp[ansId].size()) {
                ansId = i;
            }
        }
        return dp[ansId];
    }
};
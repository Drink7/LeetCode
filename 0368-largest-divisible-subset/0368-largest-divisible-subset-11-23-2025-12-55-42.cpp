class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // store LIS and current longest array
        // if new LIS found, update the longest array
        // TC: O(n^2)
        // SC: O(n)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n); // ith be the end, what is the LIS
        int maxId = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = {nums[i]};
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i].size() < dp[j].size() + 1) {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }
            }
            if (dp[i].size() > dp[maxId].size()) {
                maxId = i;
            }
        }
        return dp[maxId];
    }
};
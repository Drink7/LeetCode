class Solution {
public:
    int jump(vector<int>& nums) {
        // 1d-dp
        // TC: O(n^2)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            int minVal = 10000001;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] + j < i) {
                    continue;
                }
                minVal = min(minVal, dp[j]);
            }
            dp[i] = 1 + minVal;
        }
        return dp[n - 1];
    }
};
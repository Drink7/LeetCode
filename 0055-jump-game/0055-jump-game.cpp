class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
        // 1D DP
        // start from the last index position, then traverse back to the start index
        // TC: O(n^2)
        // SC: O(n)
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; i + j < n && j <= nums[i]; j++) {
                dp[i] = dp[i] | dp[i + j];
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[0];
        */
        // Greedy
        // TC: O(n)
        // SC: O(1)
        int reachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > reachable) {
                return false;
            }
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
};
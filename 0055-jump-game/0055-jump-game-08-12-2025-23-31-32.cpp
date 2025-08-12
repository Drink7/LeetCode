class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp[i] is true when dp[j] is true && j + nums[j] >= i
        // j < i
        // TC: O(n^2)
        // SC: O(n)
        int n = nums.size();
        vector<bool> dp(n, false);
        if (nums[0] != 0 || nums.size() == 1) {
            dp[0] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && (j + nums[j] >= i)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};
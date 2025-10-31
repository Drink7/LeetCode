class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        // brute force
        int n = nums.size();
        vector<int> dp(n, 10001);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (j + nums[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
        */
        // greedy
        // maintain a cur jump farest and the 
        int n = nums.size();
        int jumps = 0;
        int end = 0;
        int farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == end) {
                end = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};
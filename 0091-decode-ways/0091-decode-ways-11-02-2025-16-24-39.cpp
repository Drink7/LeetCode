class Solution {
public:
    int numDecodings(string s) {
        // dp[i] means the way when prev ith char can form
        // dp[i] = dp[i - 1] + dp[i - 2] (if nums[i - 1] + nums[i - 2] is valid)
        // if leading zero will be zero
        // TC: O(n)
        // SC: O(n)
        if (s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            char d1 = s[i - 1];
            int d1Num = d1 - '0';
            if (d1Num > 0 && d1Num < 10) {
                dp[i] += dp[i - 1];
            }

            if (i > 1) {
                // check two digit
                char d2 = s[i - 2];
                int d2Num = d2 - '0';
                int num = d2Num * 10 + d1Num;
                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[n];
    }
};
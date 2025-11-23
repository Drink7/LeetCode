class Solution {
public:
    int numDecodings(string s) {
        // dp[i] means the decode ways with ith be the end
        // dp[i] = dp[i - 1] if s[i - 1] is 1 ~ 9
        // + dp[i - 2] is 10 ~ 26
        // leading zero is invalid
        // TC: O(n)
        // SC: O(n)
        if (s[0] == '0') return 0;

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int digit = s[i - 1] - '0';
            if (digit >= 1 && digit <= 9) {
                dp[i] += dp[i - 1];
            }

            if (i > 1) {
                int tenDigit = s[i - 2] - '0';
                int num = tenDigit * 10 + digit;
                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[n];
    }
};
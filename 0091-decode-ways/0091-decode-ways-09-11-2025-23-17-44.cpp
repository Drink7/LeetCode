class Solution {
public:
    int numDecodings(string s) {
        // dp[i] = dp[i - 1] + 1 (if s[i] != 0) + 1 (if s[i - 1] != 0 &&  s[i]s[i-1] <= 26)
        // dp means how many ways in ith string
        // TC: O(n)
        // SC: O(1)
        int n = s.size();
        vector<int> dp(n + 1, 0);
        int result = 0;

        if (s.size() == 0 || s[0] == '0') {
            return 0;
        }

        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int numDigit = s[i - 1] - '0';

            if (numDigit > 0) {
                dp[i] += dp[i - 1];
            }

            int tenDigit = s[i - 2] - '0';
            int sum = tenDigit * 10 + numDigit;
            if (sum >= 10 && sum <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
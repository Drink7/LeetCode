class Solution {
public:
    int numDecodings(string s) {
        // dp[i] 
        // s[i] == 0 ? 0 : dp[i - 1]
        // s[i - 1], s[i] >= 10 && <= 26, dp[i - 2] : 0
        // TC: O(n)
        // SC: O(n)
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            char singleChar = s[i - 1];
            int singleNum = singleChar - '0';
            if (singleNum > 0) {
                dp[i] += dp[i - 1];
            }

            if (i - 1 - 1 >= 0) {
                char doubleChar = s[i - 1 - 1];
                int doubleNum = (doubleChar - '0') * 10 + singleNum;
                if (doubleNum >= 10 && doubleNum <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[n];
    }
};
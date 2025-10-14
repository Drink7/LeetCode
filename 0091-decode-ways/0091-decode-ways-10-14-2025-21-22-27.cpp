class Solution {
public:
    int numDecodings(string s) {
        // maxium ways
        // dp
        // TC: O(n)
        // SC: O(n)
        // dp[i] += dp[i - 1] if i >= 1 && i <= 9
        // dp[i] += dp[i - 2] if i >= 10 && i <= 26
        // dp[0] = 1
        if (s.size() > 0 && s[0] == '0') {
            return 0;
        }

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int num = stoi(s.substr(i - 2, 2));

            if (num % 10 >= 1 && num % 10 <= 9) {
                dp[i] += dp[i - 1];
            }

            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
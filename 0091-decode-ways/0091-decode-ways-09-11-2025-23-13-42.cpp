class Solution {
public:
    int numDecodings(string s) {
        // i - 2, i - 1, i
        // dp[i] += dp[i - 2] if s[i - 2 : i] is valid
        // dp[i] += dp[i - 1] if s[i] is valid
        // TC: O(n)
        // SC: O(n)
        if (s[0] == '0') {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (isValid(s.substr(i - 2, 2))) {
                dp[i] += dp[i - 2];
            }
            if (isValid(s.substr(i - 1, 1))) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[n];
    }

    bool isValid(string s) {
        if (s[0] == '0') {
            return false;
        }

        if (stoi(s) <= 26 && stoi(s) >= 1) {
            return true;
        }
        return false;
    }
};
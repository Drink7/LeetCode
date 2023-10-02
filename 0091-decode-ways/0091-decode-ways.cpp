class Solution {
public:
    int numDecodings(string s) {
        // similar to climbing stair
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
            // check 1 bit
            if (s[i - 1] != '0') {
                dp[i] = dp[i] + dp[i - 1];
            }

            if (isValid(s.substr(i - 2, 2))) {
                dp[i] = dp[i] + dp[i - 2];
            }
        }
        return dp[n];
    }

    bool isValid(string s) {
        if (s[0] == '0') {
            return false;
        }

        int num = stoi(s);
        if (num > 0 && num < 27) {
            return true;
        } else {
            return false;
        }
    }
};
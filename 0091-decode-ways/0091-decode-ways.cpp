class Solution {
public:
    int numDecodings(string s) {
        // dynamic programming
        // EX: 2314, 2 only has a decode way, 23 has [2,3] and [23] decode way
        // 231 would check the decode way of 23 and 1, and the decode way of 2 and 31
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
            // consider 1 digit
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
        } else {
            int val = stoi(s);
            if (val >= 1 && val <= 26) {
                return true;
            } else {
                return false;
            }
        }
    }
};
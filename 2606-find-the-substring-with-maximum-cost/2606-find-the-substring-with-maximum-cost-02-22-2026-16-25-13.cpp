class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        // kadane's algo
        // TC: O(m + n), m is the length of s, n is the length of chars
        // SC: O(n)
        vector<int> charDict(26, 0);
        for (int i = 0; i < 26; i++) {
            charDict[i] = i + 1;
        }

        int n = chars.size();
        for (int i = 0; i < n; i++) {
            int id = chars[i] - 'a';
            charDict[id] = vals[i];
        }

        int m = s.size();
        vector<int> dp(m + 1, -1001);
        int result = 0;
        dp[0] = 0;
        for (int i = 1; i <= m; i++) {
            dp[i] = max(dp[i - 1], 0) + charDict[s[i - 1] - 'a'];
            result = max(result, dp[i]);
        }
        return result;
    }
};
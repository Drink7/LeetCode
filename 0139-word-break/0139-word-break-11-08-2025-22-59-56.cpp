class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) { // find if i is a valid partition point
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i - j))) { // check j ... i - 1
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};
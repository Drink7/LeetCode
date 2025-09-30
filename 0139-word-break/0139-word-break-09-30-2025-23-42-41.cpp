class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] means if it is word end or not
        // TC: O(m * n)
        // SC: O(m + n)
        int n = s.size();
        unordered_map<char, vector<string>> dict;
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (auto const& word : wordDict) {
            dict[word[0]].push_back(word);
        }

        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            if (dict.count(c) > 0) {
                // traverse
                int wordListSize = dict[c].size();
                for (int j = 0; j < wordListSize; j++) {
                    int wordLen = dict[c][j].size();
                    if (dp[i - 1] && s.substr(i - 1, wordLen) == dict[c][j]) {
                        dp[i - 1 + wordLen] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};
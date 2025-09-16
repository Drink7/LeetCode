class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // hash map
        // unordered_map<char, vector<string>>
        // dp means the word
        // TC: O(m + n), m is s size, n is wordDict size
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
                // traverse all word in dict
                for (auto const& word : dict[c]) {
                    if (dp[i - 1] && s.substr(i - 1, word.size()) == word) {
                        dp[i - 1 + word.size()] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};
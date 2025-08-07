class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // maintain a dp <bool>
        // use unordered_set
        // dp[i] means could break or not at s[i]
        // go through string 1 to n
        // and check dp[n] is breakable
        // TC: O(m*n)
        // SC: O(n)
        int n = s.size();
        unordered_map<char, vector<string>> charDict;
        vector<bool> dp(n + 1, false);
        for (auto const& word : wordDict) {
            charDict[word[0]].push_back(word);
        }

        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            for (auto const& word : charDict[c]) {
                if (dp[i - 1] && s.substr(i - 1, word.size()) == word) {
                    dp[i - 1 + word.size()] = true;
                }
            }
        }
        return dp[n];
    }
};
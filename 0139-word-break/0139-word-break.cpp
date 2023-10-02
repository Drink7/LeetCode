class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // use dp to represent if we could concat the string in wordDict to s
        // TC: O(m * n), m is word dict size, n is s length
        // SC: O(n)
        unordered_map<char, vector<string>> dict;
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (auto const& word : wordDict) {
            dict[word[0]].push_back(word);
        }

        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            if (dict.count(c)) {
                for (auto const& element : dict[c]) {
                    int elementSize = element.size();
                    // previous is a valid word
                    if (dp[i - 1] && element == s.substr(i - 1, elementSize)) {
                        dp[i - 1 + elementSize] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};
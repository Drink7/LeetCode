class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] means previous ith char can be divided or not
        // store set
        // traverse s, check 0 to i
        // if dp[j] == true, s.substr(j, i) exist, means i can be divided
        // TC: O(n)
        // SC: O(n)
        int n = s.size();
        vector<bool> dp(n + 1, false);
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        dp[0] = true; // "" is valid
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};